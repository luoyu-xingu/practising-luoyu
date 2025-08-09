#include<bits/stdc++.h>

using ll = long long;
template <class T, class U>
T qpow(T a, U b) {
    T res = 1;
    for (; b != 0; b /= 2, a *= a) {
        if (b % 2 == 1) {
            res *= a;
        }
    }
    return res;
}


class Mint {
    int x;
    static int mod;

    template<class T>
    static int _to(T _x) {
        _x %= mod;

        if (_x < 0) {
            _x += mod;
        }
        
        return _x;
    }

    friend ll invGcd(ll _x, ll y);
    Mint inv() const {
        return qpow(*this, mod - 2);
    }

    public:
    Mint() : x(0) {}

    template<class T>
    Mint(T _x) : x(_to(_x)) {}

    Mint(const Mint &rhs) {
        x = rhs.x;
    }

    static int Mod() {
        return mod;
    }

    int val() {
        return x;
    }

    template<class T>
    Mint &operator= (const T &_x) {
        x = _to(_x);
        return *this;
    }

    Mint operator- () const {
        Mint res;
        if (x == 0) {
            res.x = 0;
        } else {
            res.x = (ll)mod - x;
        }
        return res;
    }

    Mint &operator-= (const Mint &rhs) {
        x = _to(1LL * x - rhs.x);
        return *this;
    }
    friend Mint operator- (Mint lhs, const Mint &rhs) {
        lhs -= rhs;
        return lhs;
    }

    Mint &operator*= (const Mint &rhs) {
        x = _to(1LL * x * rhs.x);
        return *this; 
    }

    friend Mint operator* (Mint lhs, const Mint &rhs) {
        lhs *= rhs;
        return lhs;
    }

    Mint &operator+= (const Mint &rhs) {
        x = _to(1LL * x + rhs.x);
        return *this;
    }

    friend Mint operator+ (Mint lhs, const Mint &rhs) {
        lhs += rhs;
        return lhs;
    }


    Mint &operator/= (const Mint &rhs) {
        x = _to(1LL * x * rhs.inv().x);
        return *this;
    }

    friend Mint operator/ (Mint lhs, const Mint &rhs) {
        lhs /= rhs;
        return lhs;
    }
    
    friend std::istream &operator>>(std::istream &is, Mint &self) {
        ll _x;
        is >> _x;
        self.x = _x;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &out, Mint self) {
        out << self.x;
        return out;
    }

    friend bool operator== (const Mint &lhs, const Mint &rhs) {
        return lhs.x == rhs.x;
    }

    friend std::strong_ordering operator<=> (const Mint &lhs, const Mint &rhs) {
        return lhs.x <=> rhs.x;
    }
};

ll invGcd(ll _x, ll y) {
    //  ax === 1 (mod y);
    _x = Mint::_to(_x);
    assert(_x != 0);
        
    ll s = y, t = _x;
    ll m0 = 0, m1 = 1;
 
    while (t) {
        ll u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        
        std::swap(s, t);
        std::swap(m0, m1);
    }
    
    if (m0 < 0) {
        m0 += y / s;
    }

    return m0;
} 

int Mint::mod = 998244353;
//int Mint::mod = 1e9 + 7;
using Z = Mint;


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
    
    Z rd = 0;
    bool o = 0;
    Tag() {
        rd = 0;
        o = 0;
    }

    Tag(Z x) {
        rd = x;
        o = 1;
    }

    void apply(const Tag &v) {
        if (v.o) {
            rd = v.rd;
            o = v.o;
        }
    }
};
struct Info {
    int l, r;
    Z sum;

    Info() {
        l = r = 0;
        sum = 0;
    }

    //pull操作所用
    Info(int l, int r, Z x) {
        this -> l = l;
        this -> r = r;
        sum = x;
    }
    
    //懒更新用
    void apply(Tag v) {
        if (v.o) {
            sum = (r - l + 1) * v.rd;
        }
    }

};
// pull 用
Info operator + (Info a, Info b) {

    return {a.l, b.r, a.sum + b.sum};
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

    std::vector<Z> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    LazySegment_tree<Info, Tag> tr(n, a);

    for (int i = 0; i < m; i++) {
        int l, r;
        std::cin >> l >> r;
        auto x = tr.Rquery(l, r).sum;
        tr.Rapply(l, r, x / (r - l + 1));

    }

    for (int i = 1; i <= n; i++) {
        std::cout << tr.Rquery(i, i).sum << " \n"[i == n];
    }
}