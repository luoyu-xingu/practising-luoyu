#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
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

    std::vector<std::string> s(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> s[i];
    }

    std::vector<int> pos(10, -1);
    bool ok = true;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        std::vector<int> vis(10);
        int m = 0;
        for (int j = 0; j < 3; j++) {
            if (s[j][i] != '?') {
                int k = s[j][i] - '0';
                if (pos[k] != -1 and pos[k] != i % 3) {
                    ok = false;
                }
                if (vis[k]) {
                    ok = false;
                }
                pos[k] = i % 3;
                vis[k] = 1;
            } else {
                m++;
                ans *= m;
                ans %= mod;
            }
        }
    }
    int x = 0;
    if (!ok) {
        std::cout << 0 << "\n";
    } else {
        std::vector<std::vector<int>> f(3);
        auto dfs = [&](this auto &&self, int p = 1) -> void{
            if (p == 10) {
                x++;
                return;
            }
            for (int j = 0; j < 3; j++) {
                if (f[j].size() == 3) {
                    continue;
                } 
                if (pos[p] != -1 and pos[p] != j) {
                    continue;
                } 
                f[j].push_back(p);
                self(p + 1);
                f[j].pop_back();
            }

        };
        dfs();
        std::cout << 1LL * ans * x % mod << "\n";
    }
}