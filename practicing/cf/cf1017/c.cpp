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
    std::vector g(n + 1, std::vector<int>(n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            std::cin >> g[i][j];
        }
    }
    std::vector<int> p(2 * n + 1);
    std::vector<int> che(2 * n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            assert(p[i + j] == 0 || p[i + j] == g[i][j]);
            p[i + j] = g[i][j];
            che[g[i][j]] = 1;
        }
    }
    int l = 1;
    for(int i = 1; i <= 2 * n;i++) {
        if(!p[i]) {
            while(che[l]) {
                l++;
            }
            p[i] = l;
        }
    }
    for(int i = 1; i <= 2 * n; i++) {
        std::cout << p[i] << " \n"[i == 2 * n];
    }
}