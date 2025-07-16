#include<bits/stdc++.h>

const int inf = 0x3f3f3f3f;

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


struct Tag {
    int add;
    Tag() {
        add = inf;
    }

    Tag(int x) {
        add = x;
    }

    void apply(Tag v) {}
};

struct Info {
    int l, r, lc, rc, le, re;
    ll ans;

    Info () {
        l = r = lc = rc = lc = re = ans = 0;
    }
    Info(int _l, int _r, int _x) {
        l = _l;
        r = _r;
        rc = lc = _x;
        le = re = ans = 1;
    }

    Info(int _l, int _r, int _lc, int _rc, int _le, int _re, ll _ans) {
        l = _l, r = _r, lc = _lc, rc = _rc, le = _le, re = _re, ans = _ans;
    }

    void apply(Tag x) {
        if (x.add == inf) {
            return;
        }
        rc = lc = x.add;
        le = re = 1;
        ans = 1;
    }

};


Info operator + (Info a, Info b) {
    int l = a.l, r = b.r;
    ll ans = a.ans + b.ans;
    int le, re;
    if (a.rc <= b.lc) {
        ans += 1LL * b.le * a.re;
        le = a.le + (a.le == (a.r - a.l + 1) ? b.le : 0);
        re = b.re + (b.re == (b.r - b.l + 1) ? a.re : 0);
    } else {
        le = a.le;
        re = b.re;
    }

    return {l, r, a.lc, b.rc, le, re, ans};
}

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    //std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    LazySegment_tree<Info, Tag> tr(n, a);

    while(q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y;
            std::cin >> x >> y;
            tr.Rapply(x, x, y);
        } else {
            int x, y;
            std::cin >> x >> y;
            std::cout << tr.Rquery(x, y).ans << "\n";
        }
    }
}