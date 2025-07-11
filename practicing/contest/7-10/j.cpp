
#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 3;
const int mod = 998244353;
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
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    int max = *std::max_element(a.begin() + 1, a.end());

    if (max > m) {
        for (int i = 1; i <= m; i++) {
            std::cout << "0\n";
        }
        return;
    }

/*     for (int i = 1; i < max; i++) {
        std::cout << 0 << "\n";
    } */

    auto qpow = [&](ll a, int b) {
        ll res = 1;
        for (; b; b >>= 1, a = a * a % mod) {
            if (b & 1) {
                res *= a;
                res %= mod;
            }
        }
        return res;
    };

    std::vector<ll> fact(N + 1, 1), inv(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv[N] = qpow(fact[N], mod - 2);
    for (int i = N - 1; i >= 1; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }

    auto C = [&](int x, int y) {
        if (x > y || x < 0) {
            return 0LL;
        }
        return fact[y] * inv[x] % mod * inv[y - x] % mod;
    };

    std::vector<int> cnt(N + 1);

    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }

    std::vector<int> c;
    for (int i = 0; i <= N; i++) {
        if (cnt[i]) {
            c.push_back(i);
        }
    }

    for (int i = 1; i < max; i++) {
        std::cout << 0 << "\n";
    }

    for (int i = max; i <= m; i++) {
        ll ans = 1;
        for (auto x : c) {
            ans *= qpow(C(x, i), cnt[x]);
            ans %= mod;
        }
        std::cout << ans << "\n";
    }


}