#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
std::vector<ll> sum;
const int N = 3e5 + 7;

void init(int n) {
    sum.assign(n + 1, 0LL);
    for(int i = 1; i <= n; i++) {
        sum[i] = (sum[i - 1] + 1LL * i * i % mod) %mod;
    }
} 
void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    init(N);
    int t = 1;
    std::cin >> t;
    while(t--) solve();
    return 0;
}
void solve(){
    int n;
    ll k;
    std::cin >> n >> k;
    ll ans = 0;

    auto qpow = [&](ll a, int b) {
        ll res = 1;
        for(;b; b >>= 1, a = a * a % mod) {
            if(b & 1) {
                res *= a;
                res %= mod;
            }
        }
        return res;
    };
    if(k > n) {
        ans += (k - n + mod) % mod * n % mod;
    }

    if(k > sqrt(n)) {
        ll m = std::min<ll>(k, n);
        int l = sqrt(n) + 1;
        ans += 1LL * n * (l + m) % mod *(m - l + 1) % mod * qpow(2, mod - 2) % mod;

        for(int i = l, r = l; i <= m; i = r + 1) {
            ll v = n / i;
            assert(v > 0);
            r = std::min(n / v, k);
            ans += v * (r - i + 1) % mod;
            ans %= mod;
            ans -=  v * (sum[r] - sum[i - 1] + mod) % mod;
            ans = (ans + mod) % mod;
        }
    }
    ll m = std::min<ll>(k, sqrt(n));
    for(int i = 2; i <= m; i++) {
        std::vector<int> res;
        int w = n;
        while(w) {
            res.push_back(w % i);
            w /= i;
        }
        while(!res.empty() and res.back() == 0) {
            res.pop_back();
        }

        ll r = 0;
        ll q = 1;
        for(int j = res.size() - 1; j >= 0; j--) {
            r += res[j] * q % mod;
            r %= mod;
            q *= i;
            q %= mod;
        }
        ans += r;
        ans %= mod;
       // std::cout << r << "\n";
    }
    std::cout << ans << "\n";
}
