#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
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
    int l, r, k;
    std::cin >> l >> r >> k;

    int p = 0;
    while(p <= 9 and 1LL * (p + 1) * k < 10) {
        p++;
    }

    auto qpow = [&](ll a, int b) {
        ll res = 1;
        for (;b; b >>= 1, a = a * a % mod) {
            if (b & 1) {
                res = res * a % mod;
            }
        }
        return res;
    };

    //std::cout << p << "\n";
    std::cout << ((qpow(p + 1, r) - qpow(p + 1, l)) + mod) % mod << "\n";
}