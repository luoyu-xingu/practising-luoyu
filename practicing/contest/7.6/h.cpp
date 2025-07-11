#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(15);

    int t = 1;
    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n, k;
    std::cin >> n >> k;

    std::vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];

    }

    sort(a.begin() + 1, a.end(), std::greater<ll>());
    
    ll ans = 1;
    bool ok = false;
    for (int i = 1; i <= k; i++) {
        ans *= a[i];
        ans %= mod;
        if (a[i] == 0) {
            ok = true;
        }
    }

    ll max = a[1] % mod;
    // i == nk - 1;
    // 1 - k;
    // k - 2(k - 1) + 1
    // 2k -- 3(k - 1) + 1;
    if (ok) {
        std::cout << a[1] % mod << "\n";
        return ;
    } else {
        max = ans;
        ans = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                break;
            }
            ans *= a[i];
            ans %= mod;
            if ((i - 1) % (k - 1) == 0) {
                max = ans;
            }
        }
    }

    std::cout << max << "\n";
}