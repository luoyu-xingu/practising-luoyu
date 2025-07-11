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

struct Tag {
    int add;

    Tag() {
        add = INT_MIN;
    }

    Tag(int x) {
        add = x;
    }

    void apply(const Tag &v) {
        add = v.add;
    }
};

struct Info {
    int l, r;
    int max;
    Info() {
        l = r = 0;
        max = -inf;
    }

    Info(int l, int r, int x) {
        this -> l = l;
        this -> r = r;
        max = x;
    }
    
    //懒更新用
    void apply(Tag v) {
        if (v.add != INT_MIN) {
            max = v.add;
        }
    }
};
// pull 用
Info operator + (Info a, Info b) {
    auto [_l, _r] = std::minmax({a.l, a.r, b.l, b.r});
    return {_l, _r, std::max(a.max, b.max)};
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

    std::vector<int> a(n + 1, -inf);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    LazySegment_tree<Info, Tag> tr(n, a);

    std::vector e(n + 1, std::vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    int max = *std::max_element(a.begin() + 1, a.end());
    int ans = max + 2;


    for (int i = 1; i <= n; i++) {
        int res = a[i];
        tr.Rapply(i, i, -inf);
        int p = -inf;
        for (auto x : e[i]) {
            p = std::max(p, a[x]);
            tr.Rapply(x, x, -inf);
        }

        res = std::max({res, p + 1, tr.Rquery(1, n).max + 2});

        ans = std::min(ans, res);
        tr.Rapply(i, i, a[i]);
        for (auto x : e[i]) {
            tr.Rapply(x, x, a[x]);
        }
    }

    std::cout << ans << "\n";
}