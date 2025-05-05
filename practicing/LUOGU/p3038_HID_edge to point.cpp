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
    int add;

    Tag() {
        add = 0;
    }

    Tag(int x) {
        add = x;
    }

    void apply(const Tag &v) {
        add += v.add;
    }
};
struct Info {
    int l, r;
    int sum;
    Info() {
        l = r = sum = 0;
    }

    //pull操作所用
    Info(int l, int r, int x) {
        this -> l = l;
        this -> r = r;
        sum = x;
    }
    
    //懒更新用
    void apply(Tag v) {
        sum += (r - l + 1) * v.add;
    }

    int getinfo() {
        return sum;
    }
};
// pull 用
Info operator + (Info a, Info b) {
    auto [l, r] = std::minmax({a.l, a.r, b.l, b.r});
    return {l, r, a.sum + b.sum};
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
    std::vector<int> a(n + 1);

    std::vector e(n + 1, std::vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    std::vector<int> dep(n + 1), fa(n + 1), dfn(n + 1), hson(n + 1), sze(n + 1), top(n + 1);
    auto dfs = [&](auto &&self, int u, int f) -> void {
        dep[u] = dep[f] + 1;
        fa[u] = f;
        sze[u] = 1;
        for (auto v : e[u]) { 
            if (v == f) {
                continue;
            }
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
        top[u] = f;
        if (hson[u] != 0) {
            self(self, hson[u], f);
        }
        for (auto v : e[u]) {
            if (v == hson[u] || v == fa[u]) {
                continue;
            }
            self(self, v, v);
        }
    };

    Set(Set, 1, 1);
    LazySegment_tree<Info, Tag> tr(n, a);
    while (m--) {
        char op;
        std::cin >> op;
        if (op == 'P') {
            int x, y;
            std::cin >> x >> y;
            while (top[x] != top[y]) {
                if (dep[top[x]] > dep[top[y]]) {
                    tr.Rapply(dfn[top[x]], dfn[x], 1);
                    x = fa[top[x]];
                } else {
                    tr.Rapply(dfn[top[y]], dfn[y], 1);
                    y = fa[top[y]];
                } 
            }
            tr.Rapply(std::min(dfn[x], dfn[y]) + 1, std::max(dfn[x], dfn[y]), 1);
        } else {
            int x, y;
            std::cin >> x >> y;
            if (dfn[x] > dfn[y]) {
                std::cout << tr.Rquery(dfn[x], dfn[x]).sum << "\n";
            } else {
                std::cout << tr.Rquery(dfn[y], dfn[y]).sum << "\n";
            }
        }
    }

}