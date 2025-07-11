#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    //std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    int n, t;
    std::cin >> n >> t;

    std::vector e(n, std::vector<std::pair<int, int>>());
    
    for (int i = 1; i <= t; i++) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; j++) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            e[u].emplace_back(v, i);
            e[v].emplace_back(u, i);
        }
    }

    int k;
    std::cin >> k;
    std::vector<int> a(k + 1);
    for (int i = 1; i <= k; i++) {
        std::cin >> a[i];
    }

    std::vector T(t + 1, std::vector<int>());
    for (int i = 1; i <= k; i++) {
        T[a[i]].push_back(i);
    }

    std::vector<int> d(n, inf);
    d[0] = 0;

    std::priority_queue<std::pair<int, int>, 
            std::vector<std::pair<int, int>>,
            std::greater<std::pair<int, int>>> pq;
    pq.push({d[0], 0});

    std::vector<char> vis(n);
    

    while(!pq.empty()) {
        auto [_, u] = pq.top();
        pq.pop();

        if (vis[u]) {
            continue;
        }

        vis[u] = 1;

        for (auto [v, q] : e[u]) {
            auto f = std::upper_bound(T[q].begin(), T[q].end(), d[u]);
            if (f == T[q].end()) {
                continue;
            }

            if (d[v] > *f) {
                d[v] = *f;
                pq.emplace(d[v], v);
            }
        }
    }

    if (d[n - 1] == inf) {
        std::cout << -1 << "\n";
    } else {
        std::cout << d[n - 1] << "\n";
    }
    
}