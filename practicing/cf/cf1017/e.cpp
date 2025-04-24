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
    std::cin >> t;
    while(t--) solve();
    return 0;
}
void solve(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> cnt(30);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 30; j++) {
            if((a[i] >> j) & 1) cnt[j]++;
        }
    }
    ll ans = 0;
    for(int k = 0; k < n; k++) {
        ll res = 0;
        for(int j = 0; j < 30; j++) {
            if((a[k] >> j) & 1) {
                res += 1LL * (1 << j) * (n - cnt[j]);
            }
            else {
                res += 1LL * (1 << j) * cnt[j];
            }
        }
        ans = std::max(ans, res);
    }
    std::cout << ans << '\n';
 
}