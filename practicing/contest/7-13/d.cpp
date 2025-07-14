#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    int n, m, h;
    std::cin >> n >> m >> h;

    std::vector<int> a(n, 0);
    for (int i = 0; i < h; i++) {
        int x;
        std::cin >> x;
        x--;
        a[x] = 1;
    }

    std::vector e(n, std::vector<std::pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--,v--;
    
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }

    auto dijkstra = [&](std::vector<std::vector<ll>> &dp,int s) {
        for (int i = 0; i < n; i++) {
            dp[0][i] = dp[1][i] = Inf;
        }

        dp[0][s] = 0;

        std::priority_queue<std::tuple<ll, int, bool>,
                            std::vector<std::tuple<ll, int, bool>>,
                            std::greater<std::tuple<ll, int, bool>>> pq;
        pq.emplace(dp[0][s], s, 0);
        std::vector<int> vis(2 * n);

        while(!pq.empty()) {
            auto [_, u, o] = pq.top();
            pq.pop();

            if (vis[u + o * n]) {
                continue;
            }

            vis[u + o * n] = 1;

            for (auto[v, w] : e[u]) {
                int h = o || a[u];
                if (dp[h][v] > dp[o][u] + w / (h + 1)) {
                    dp[h][v] = dp[o][u] + w / (h + 1);
                    pq.emplace(dp[h][v], v, h);
                }
            }
        }
    };

    std::vector dp(2, std::vector<ll>(n));
    auto ndp = dp;

    dijkstra(dp, 0);
    dijkstra(ndp, n - 1);

    ll min = Inf;

    //std::cout << dp[0][1] << " " << "\n";
    //std::cout << ndp[0][1] << " " << "\n";
    for (int i = 0; i < n; i++) {
        ll min1 = std::min(dp[0][i], dp[1][i]);
        ll min2 = std::min(ndp[0][i], ndp[1][i]);

        min = std::min(min, std::max(min1, min2));
    }

    if (min >= Inf) {
        std::cout << -1 << "\n";
    } else {
        std::cout << min << "\n";
    }
}