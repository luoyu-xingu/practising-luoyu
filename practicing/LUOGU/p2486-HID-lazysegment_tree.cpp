#include<bits/stdc++.h>

using ll = long long;

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
    int M;

    Tag() {
        M = 0;
    }

    Tag(int x) {
        M = x;
    }

    void apply(const Tag &v) {
        if (v.M != 0) {
            M = v.M;
        }
    }
};
struct Info {
    int l, r;
    int lc, rc, ans;
    Info() {
        l = r = ans = 0;
        lc = rc = ans;
    }

    //pull操作所用
    Info(int l, int r, int x) {
        this -> l = l;
        this -> r = r;
        lc = rc = x;
        ans = 1;
    }
    
    Info(int l, int r, int lc, int rc, int ans) {
        this -> l = l;
        this -> r = r;
        this -> lc = lc;
        this -> rc = rc;
        this -> ans = ans;
    }

    //懒更新用
    void apply(Tag v) {
        if (v.M == 0) {
            return;
        }

        ans = 1;
        lc = rc = v.M;
    }

    int getinfo() {
        return ans;
    }
};
// pull 用
Info operator + (Info a, Info b) {
    int l, r, lc, rc, ans;
    if (a.ans == 0) {
        l = b.l, r = b.r;
        lc = b.lc, rc = b.rc;
        ans = b.ans;
    } else if (b.ans == 0) {
        l = a.l, r = a.r;
        lc = a.lc, rc = a.rc;
        ans = a.ans;
    } else {
        l = a.l;
        r = b.r;
        lc = a.lc;
        rc = b.rc;
        ans = a.ans + b.ans - (b.lc == a.rc);
    }
    return {l, r, lc, rc, ans};
}

void solve();
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    int r = 1;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    std::vector<int> hson(n + 1), dep(n + 1), top(n + 1), dfn(n + 1), rdfn(n + 1), fa(n + 1), sze(n + 1);
    auto dfs = [&](auto &&self, int u, int f) -> void {
        fa[u] = f;
        dep[u] = dep[f] + 1;
        sze[u] = 1;
        for (auto v : e[u]) {
            if (v == f) {
                continue;
            } 
            self(self, v, u);
            sze[u] += sze[v];
            if (sze[v] > sze[hson[u]]) {
                hson[u] = v;
            }
        }
    };
    dfs(dfs, r, r);

    int cur = 0;
    auto Set = [&](auto &&self, int u, int f) -> void {
        top[u] = f;
        dfn[u] = ++cur;
        rdfn[cur] = u;

        if (hson[u] == 0) {
            return;
        }

        self(self, hson[u], f);
        for (auto v : e[u]) {
            if (v == hson[u] || v == fa[u]) {
                continue;
            }
            self(self, v, v);
        }
    };
    Set(Set, r, r);

    std::vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        c[i] = a[rdfn[i]];
    }

    LazySegment_tree<Info, Tag> tr(n, c);

    while (m--) {
        char op;
        std::cin >> op;
        if (op == 'C') {
            int x, y, k;
            std::cin >> x >> y >> k;

            while (top[x] != top[y]) {
                if (dep[top[x]] > dep[top[y]]) {
                    tr.Rapply(dfn[top[x]], dfn[x], k);
                    x = fa[top[x]];
                } else {
                    tr.Rapply(dfn[top[y]], dfn[y], k);
                    y = fa[top[y]];
                }
            }

            tr.Rapply(std::min(dfn[x], dfn[y]), std::max(dfn[x], dfn[y]), k);
        } else {
            int x, y;
            std::cin >> x >> y;
            Info ansx, ansy;
            while (top[x] != top[y]) {
                if (dep[top[x]] > dep[top[y]]) {
                    ansx = tr.Rquery(dfn[top[x]], dfn[x]) + ansx;
                    x = fa[top[x]];
                } else {
                    ansy =tr.Rquery(dfn[top[y]], dfn[y]) + ansy;
                    y = fa[top[y]];
                }
            }
            assert(top[x] == top[y]);
            int ans = 0;
            if (dep[x] > dep[y]) {
                ansx = tr.Rquery(dfn[y], dfn[x]) + ansx;
                ans += ansx.ans + ansy.ans;
                if (ansx.lc == ansy.lc) {
                    ans--;
                }
            } else {
                ansy = tr.Rquery(dfn[x], dfn[y]) + ansy;
                ans = ansx.ans + ansy.ans;
                if (ansy.lc == ansx.lc) {
                    ans--;
                }
            }
            std::cout << ans << "\n";
        }
    }
}