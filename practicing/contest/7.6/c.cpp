#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

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

    friend ll invGcd(ll _x);
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
    Mint operator= (T _x) {
        x = to(_x);
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

ll invGcd(ll _x) {
    //  ax === 1 (mod y);
    _x = Mint::_to(_x);
    assert(_x != 0);
        
    ll s = Mint::mod, t = _x;
    ll m0 = 0, m1 = 1;
 
    while (t) {
        ll u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        
        std::swap(s, t);
        std::swap(m0, m1);
    }
    
    if (m0 < 0) {
        m0 += Mint::mod / s;
    }

    return m0;
} 

int Mint::mod = 998244353;
//int Mint::mod = 1e9 + 7;
using Z = Mint;
Z p0, p1;
Z lse1(int x, int y);
Z lse(int x, int y);


Z lse1 (int x, int y) {
    if (x == y) {
        return p1;
    }
    if(x <= 0 || y <= 0) {
        assert(false);
    }
    if (x < y) {
        return 1 - lse(x, y);
    }

    ll lo = (x + y - 1) / y - 1;

    return qpow(p1, lo) * lse1(x - 1LL * lo * y, y);

};

Z lse(int x, int y) {
    if (x == y) {
        return p0;
    }
    if(x <= 0 || y <= 0) {
        assert(false);
    }
    if (y < x) {
        return 1 - lse1(x, y);
    }

    // x < y;
    ll lo = (y + x - 1) / x - 1;

    return qpow(p0, lo) * lse(x, y - 1LL * lo * x);

};


void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    Z a, b, d;
    int x, y;
    std::cin >> x >> y;
    std::cin >> a >> b >> d;

    d = a + b;

    p0 = a / d;
    p1 = b / d;


    std::cout << lse(x, y) << "\n";
}