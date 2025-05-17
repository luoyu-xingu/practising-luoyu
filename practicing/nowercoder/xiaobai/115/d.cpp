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
    while(t--) solve();
    return 0;
}
void solve(){
    int n;
    std::cin >> n;

    std::vector<std::string> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int d = a[0].size();
    for (int i = 1; i < n; i++) {
        d = std::gcd(d, a[i].size());
    }

    std::map<std::string, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i].size(); j += d) {
            mp[a[i].substr(j, d)]++;
        }
    }
    
    int v = 0;
    int ans = 0;
    
    for (int i = 0; i < d; i++) {
        std::vector<int> ch(300);
        int sze = 0;
        for (auto [x, y] : mp) {
            sze += y;
            ch[x[i]] += y;
        }
        int v = *std::max_element(ch.begin(), ch.end());
        ans += sze - v;
    }

    std::cout << ans << "\n";
}