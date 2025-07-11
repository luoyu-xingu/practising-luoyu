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

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n, m;
    std::cin >> n >> m;

    std::cout << "YES\n";
    if (m % 2 == 0) {
        int tot = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                std::cout << tot++ << " \n"[j == m];
            }
        }
    } else {
        int tot = 1;
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                for (int j = 1; j <= m; j++) {
                    std::cout << tot++ << " \n"[j == m];
                } 
            } else {
                std::cout << i * m << " ";
                for (int j = 2; j <= m; j++) {
                    std::cout << tot++ << " ";
                }
                tot++;
                std::cout << "\n";
            }
        }
    }
}