#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll Inf = 0x3f3f3f3f3f3f3f3f;

template<class Info, class Tag>
class LazySegment_tree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    void pull_up(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    template<class T>
    void build(int p, int l, int r, const std::vector<T> &a) {
        info[p].l = l, info[p].r = r;
        if (l == r) {
            info[p] = {l, r, a[l]};
            return;
        }
        int mid = l + r >> 1;
        build(2 * p, l, mid, a);
        build(2 * p + 1, mid + 1, r, a);
        pull_up(p);
    }

    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push_down(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }

    void rangeApply(int p, int l, int r, int x, int y, Tag v) {
        if (y < x) {
            return;
        }
        if (x <= l and y >= r) {
            apply(p, v);
            return;
        }
        int mid = l + r >> 1;
        push_down(p);
        if (x <= mid) {
            rangeApply(2 * p, l, mid, x, y, v);
        } 
        if (y > mid) {
            rangeApply(2 * p + 1, mid + 1, r, x, y, v);
        }
        pull_up(p);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (y < x) {
            return Info();
        }
        if (x <= l and y >= r) {
            return info[p];
        }

        int mid = l + r >> 1;
        push_down(p);
        if (x > mid) {
            return rangeQuery(2 * p + 1, mid + 1, r, x, y);
        } else if (y <= mid) {
            return rangeQuery(2 * p, l, mid, x, y);
        }

        return rangeQuery(2 * p, l, mid, x, y) + rangeQuery(2 * p + 1, mid + 1, r, x, y);
    }

    public:
    template<class T>
    LazySegment_tree(int _n, const std::vector<T> &a) {
        n = _n;
        info.assign(4 * n + 7, Info());
        tag.assign(4 * n + 7, Tag());
        build(1, 1, n, a);
    }

    void Rapply(int x, int y, Tag v) {
        rangeApply(1, 1, n, x, y, v);
    }

    Info Rquery(int x, int y) {
        return rangeQuery(1, 1, n, x, y); 
    }
};

// 以下为带修改部分， 主要为懒更新的使用和维护信息
//下面为区间和版本
struct Tag {
    ll add;
    ll ch;

    Tag() {
        add = 0;
        ch = -Inf;
    }

    Tag(int op, ll x) {
        if (op == 1) {
            ch = x;
            add = 0;
        } else {
            add = x;
            ch = -Inf;
        }
    }

    void apply(const Tag &v) {
        if (v.ch != -Inf) {
            ch = v.ch;
            add = v.add;
        } else {
            add += v.add;
        }
    }
};

struct Info {
    int l, r;
    ll max;
    Info() {
        l = r = 0;
        max = -Inf;
    }

    //pull操作所用
    Info(int l, int r, ll x) {
        this -> l = l;
        this -> r = r;
        max = x;
    }
    
    //懒更新用
    void apply(Tag v) {
        if (v.ch != -Inf) {
            max = v.ch;
        }

        max += v.add;
    }

    ll getinfo() {
        return max;
    }
};
// pull 用
Info operator + (Info a, Info b) {
    auto [l, r] = std::minmax({a.l, a.r, b.l, b.r});
    return {l, r, std::max(a.max, b.max)};
}

void solve();
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);

    std::vector<std::array<int, 3>> adj(n);
    std::vector<std::vector<std::pair<int, int>>> e(n + 1); 
    for (int i = 1; i < n; i++) {
        std::cin >> adj[i][0] >> adj[i][1] >> adj[i][2];
        e[adj[i][0]].emplace_back(adj[i][1], adj[i][2]);
        e[adj[i][1]].emplace_back(adj[i][0], adj[i][2]);
    }

    std::vector<int> dep(n + 1), fa(n + 1), dfn(n + 1), hson(n + 1), sze(n + 1), top(n + 1), rdfn(n + 1);
    auto dfs = [&](auto &&self, int u, int f) -> void {
        dep[u] = dep[f] + 1;
        fa[u] = f;
        sze[u] = 1;
        for (auto [v, w] : e[u]) { 
            if (v == f) {
                continue;
            }
            a[v] = w;
            self(self, v, u);
            sze[u] += sze[v];
            if (sze[hson[u]] < sze[v]) {
                hson[u] = v;
            }
        }
    };

    dfs(dfs, 1, 1);

    int cur = 0;
    auto Set = [&](auto &&self, int u, int f) -> void {
        dfn[u] = ++cur;
        rdfn[cur] = u;
        top[u] = f;
        if (hson[u] != 0) {
            self(self, hson[u], f);
        }
        for (auto [v, _] : e[u]) {
            if (v == hson[u] || v == fa[u]) {
                continue;
            }
            self(self, v, v);
        }
    };

    Set(Set, 1, 1);
    std::vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        c[i] = a[rdfn[i]];
    }

    LazySegment_tree<Info, Tag> tr(n, c);
    while (1) {
        std::string s;
        std::cin >> s;
        if (s == "Change") {
            int k, v;
            std::cin >> k >> v;
            int x = adj[k][0];
            int y = adj[k][1];
            if (dfn[x] < dfn[y]) {
                tr.Rapply(dfn[y], dfn[y], {1, v});
            } else {
                tr.Rapply(dfn[x], dfn[x], {1, v});
            }
        } else if (s == "Cover") {
            int x, y, k;
            std::cin >> x >> y >> k;
            while (top[x] != top[y]) {
                if (dep[top[x]] > dep[top[y]]) {
                    tr.Rapply(dfn[top[x]], dfn[x], {1, k});
                    x = fa[top[x]];
                } else {
                    tr.Rapply(dfn[top[y]], dfn[y], {1, k});
                    y = fa[top[y]];
                } 
            }
            tr.Rapply(std::min(dfn[x], dfn[y]) + 1, std::max(dfn[x], dfn[y]), {1, k});
        } else if (s == "Add") {
            int x, y, k;
            std::cin >> x >> y >> k;
            while (top[x] != top[y]) {
                if (dep[top[x]] > dep[top[y]]) {
                    tr.Rapply(dfn[top[x]], dfn[x], {2, k});
                    x = fa[top[x]];
                } else {
                    tr.Rapply(dfn[top[y]], dfn[y], {2, k});
                    y = fa[top[y]];
                } 
            }
            tr.Rapply(std::min(dfn[x], dfn[y]) + 1, std::max(dfn[x], dfn[y]), {2, k});
        } else if (s == "Max"){
            int x, y;
            std::cin >> x >> y;
            Info ans;
           // std::cout << ans.max << "\n";
            while (top[x] != top[y]) {
                if (dep[top[x]] > dep[top[y]]) {
                    ans = ans + tr.Rquery(dfn[top[x]], dfn[x]);
                    x = fa[top[x]];
                } else {
                    ans = ans + tr.Rquery(dfn[top[y]], dfn[y]);
                    y = fa[top[y]];
                }
            //    std::cout << ans.max << "\n"; 
            }
            ans = ans + tr.Rquery(std::min(dfn[x], dfn[y]) + 1, std::max(dfn[x], dfn[y]));
            std::cout << ans.max << "\n";
        } else {
            return;
        }
    }

}