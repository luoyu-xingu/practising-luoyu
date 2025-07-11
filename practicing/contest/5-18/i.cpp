#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
void solve();
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(15);

    int t = 1;
//    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> e(n + 1);
    for (int i = 1; i < n; i++) {
        e[i].push_back(i + 1);
    }
    e[n].push_back(1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
    }

    

}