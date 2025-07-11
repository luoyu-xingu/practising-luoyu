#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(15);

    int t = 1;
    //std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    ll n, m;
    std::cin >> n >> m;

    int cnt = 0;
    if (n >= m) {
        std::cout << n - m << "\n";
    } else {
        std::map<ll, ll> mp;
        auto dfs = [&](auto &&self, ll x) {
            if (x <= n) {
                return n - x;
            }
            if (mp[x]) {
                return mp[x];
            }
            if (x % 2 == 0) {
                return std::min<ll>(self(self, x / 2) + 1, x - n);
            }
            ll ans = self(self, x + 1);
            ans = std::min<ll>(ans, self(self, x - 1));
            return mp[x] = ans + 1;
        };
       std::cout << dfs(dfs, m) << "\n";    
    }

}