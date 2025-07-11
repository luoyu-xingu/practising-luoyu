#include<bits/stdc++.h>

using ll = long long;

template<class T> 
class Frac {
    T f, g;
    void _to() {
        T gcd = std::gcd(std::abs(f), std::abs(g));
        if (g < 0) {
            g = -g;
            f = -f;
        }
        f /= gcd;
        g /= gcd;
        
    }

    public:

    Frac() {
        f = 0, g = 1;
    }

    Frac(T _f, T _g) {
        f = _f, g = _g;
        _to();
    }

    Frac(T _num) : Frac(_num, 1) {}
    
    Frac(const Frac &rhs) {
        f = rhs.f;
        g = rhs.g;
        _to();
    }

    explicit operator double() const {
        return 1.0 * f / g;
    }
    Frac operator-() {
        return {-f, g};
    }

    Frac &operator+=(const Frac &rhs) {
        f = f * rhs.g + rhs.f * g;
        g *= rhs.g;
        _to();
        return *this;
    }

    Frac &operator-=(const Frac &rhs) {
        f = f * rhs.g - rhs.f * g;
        g *= rhs.g;
        _to();
        return *this;
    }

    Frac &operator*=(const Frac &rhs) {
        f *= rhs.f;
        g *= rhs.g;
        _to();
        return *this;
    }

    Frac &operator/=(const Frac &rhs) {
        f *= rhs.g;
        g *= rhs.f;
        _to();
        return *this;
    }

    friend Frac operator+(Frac lhs, const Frac &rhs) {
        return lhs += rhs;
    }
    friend Frac operator-(Frac lhs, const Frac &rhs) {
        return lhs -= rhs;
    }
    friend Frac operator*(Frac lhs, const Frac &rhs) {
        return lhs *= rhs;
    }
    friend Frac operator/(Frac lhs, const Frac &rhs) {
        return lhs /= rhs;
    }

    friend bool operator==(const Frac &lhs, const Frac &rhs) {
        return lhs.f * rhs.g == rhs.f * lhs.g;
    }
    friend bool operator!=(const Frac &lhs, const Frac &rhs) {
        return lhs.f * rhs.g != rhs.f * lhs.g;
    }
    friend bool operator<(const Frac &lhs, const Frac &rhs) {
        return lhs.f * rhs.g < rhs.f * lhs.g;
    }
    friend bool operator>(const Frac &lhs, const Frac &rhs) {
        return lhs.f * rhs.g > rhs.f * lhs.g;
    }
    friend bool operator<=(const Frac &lhs, const Frac &rhs) {
        return lhs.f * rhs.g <= rhs.f * lhs.g;
    }
    friend bool operator>=(const Frac &lhs, const Frac &rhs) {
        return lhs.f * rhs.g >= rhs.f * lhs.g;
    }

    std::pair<T, T> val() {
        return {f, g};
    }
};

using Z = Frac<ll>;
void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {

    int n, k;
    std::cin >> n >> k;

    std::vector<std::array<int, 2>> p(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i][0] >> p[i][1];
    }

    std::vector<std::array<int, 2>> ch;
    std::map<int, bool> mp; 
    ll ans = 0;
    auto check = [&](std::array<int, 2> p1, std::array<int, 2> p2, std::array<int, 2> p3) -> bool {
        return 1LL * (1LL * p3[0] - p1[0]) * (1LL * p2[1] - p1[1]) == 1LL * (1LL * p3[1] - p1[1]) * (1LL * p2[0] - p1[0]); 
    };

    std::set<std::pair<Z, Z>> s;
    auto dfs = [&](auto &&self, int m, int l) {
        if (m == 2) {
            assert(ch.size() == 2);
            auto p1 = ch[0], p2 = ch[1];
            if (p1[0] == p2[0] and p1[1] == p2[1]) {
                return ;
            }

            if (p1[0] == p2[0]) {
                if (mp[p1[0]]) {
                    return;
                } else {
                    mp[p1[0]] = 1;
                    int cnt = 0;
                    for (int i = 1; i <= n; i++) {
                        if (p1[0] == p[i][0]) {
                            cnt++;
                        }
                    }
                    if (cnt >= k) {
                        ans++;
                    }
                    return; 
                }
            } else {

                Z z = {p2[1] - p1[1], p2[0] - p1[0]};
                Z b = -z * p1[0] + p1[1];
                if (s.contains({z, b})) {
                    return ;
                }
 
                s.insert({z, b});
                int cnt = 0;
                for (int i = 1; i <= n; i++) {
                    if (check(p1, p2, p[i])) {
                        cnt++;
                    }
                }
                if (cnt >= k) {
                    ans++;
                }
                return;
            }
            return;
        }


        for (int i = 1; i <= n; i++) {
            ch.push_back(p[i]);
            self(self, m + 1, i);
            ch.pop_back();
        }
    };
    if (k == 1) {
        std::cout << "Infinity\n";
        return;
    }

    dfs(dfs, 0, 0);

/*     for (auto x : s) {
        auto [p, q] = x;
        auto [o, u] = p.val();
        std::cout << o << "/" << u << "\n";
    } */
    std::cout << ans << "\n";

}