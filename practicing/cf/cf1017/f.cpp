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
    int n, m, k;
    std::cin >> n >> m >> k;
    int p = 1;
    std::vector g(n + 1, std::vector<int>(m + 1));
    if(m % k != 0) {
        int x = 1;
        for(int i = 1; i <= n; i++) {
            for(int  j = 1; j <= m; j++) {
                g[i][j] = x++;
                if(x == k + 1) {
                    x = 1;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                std::cout << g[i][j] << " \n"[j == m];
            }
        }
    }
    else {
        int x = 1;
        for(int j = 1; j <= m; j++) {
            g[1][j] = x++;
            if(x == k + 1) x = 1;
        }
        x = 2;
        if(n > 1) {
            for(int j = 1; j <= m; j++) {
                g[2][j] = x++;
                if(x == k + 1) x = 1;
            }
        }
        for(int i = 3; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                g[i][j] = g[(i % 2) == 0 ? 2 : 1][j];
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                std::cout << g[i][j] << " \n"[j == m];
            }
        }
    }
}