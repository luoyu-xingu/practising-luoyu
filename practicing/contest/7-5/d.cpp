#include<bits/stdc++.h>
using ll = long long;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector e(n + 1, std::vector<std::pair<int, int>>());
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;

        if (a[u] >= a[v]) {
            e[u].emplace_back(v, 0);
            e[v].emplace_back(u, a[u] - a[v]);
        } else {
            e[v].emplace_back(u, 0);
            e[u].emplace_back(v, a[v] - a[u]);
        }
    }

    std::vector dis(n + 1, Inf);
    auto dijkstra = [&](int s) {
        dis[s] = 0;
        std::vector<int> vis(n + 1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,std::greater<std::pair<int, int>>> pq;
        pq.emplace(dis[s], s);
        while(!pq.empty()) {
            auto [_, u] = pq.top();
            pq.pop();
            if(vis[u]) continue;
            for(auto [v, w] : e[u]) {
                if(dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.emplace(dis[v], v); 
                }
            }
        }
    };

    dijkstra(1);

    int max = -1;
    for (int i = 1; i <= n; i++) {
        max = std::max<ll>(max, a[1] - a[i] - dis[i]);
    }

    std::cout << max << "\n";
}

