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
    int n, m, l;
    std::cin >> n >> m >> l;

    std::vector<int> a(l);
    for (int i = 0; i < l; i++) {
        std::cin >> a[i];
    }

    std::vector e(n, std::vector<int>());
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    } 

    const int M = 2e9 + 7;
    std::vector<std::array<int, 2>> dis(n, {M, M});
    {
        std::queue<std::array<int, 2>> q;
        dis[0][0] = 0;
        q.push({0, 0});
        
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto v : e[x]) {
                if (dis[v][!y] > dis[x][y] + 1) {
                    dis[v][!y] = dis[x][y] + 1;
                    q.push({v, !y});
                }
            }
        }
    }

    std::vector<int> max(2, 0);
    int sum = std::accumulate(a.begin(), a.end(), 0);
    max[sum % 2] = sum;
    for (int i = 0; i < l; i++) {
        int x = sum - a[i];
        max[x % 2] = std::max(max[x % 2], x);
    }

    // max 最大可以到 2e9
    for (int i = 0; i < n; i++) {
        std::cout << (dis[i][0] <= max[0] || dis[i][1] <= max[1]);
    }
    std::cout << "\n";

}