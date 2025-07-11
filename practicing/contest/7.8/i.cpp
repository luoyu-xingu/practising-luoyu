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
    int n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector e(n + 1, std::vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        e[u].emplace_back(v);
    }

    std::vector<char> vis(n), g(n);
    std::vector<std::array<int, 26>> cnt(n); 
    int ans = -1;
    auto dfs = [&](auto &&self, int u) -> void {
        g[u] = 1;
        vis[u] = 1;
        for (auto v : e[u]) {
            if (vis[v]) {
                std::cout << -1 << "\n";
                exit(0);
            }
            if (!g[v]) {
                self(self, v);
            }
            for (int i = 0; i < 26; i++) {
                cnt[u][i] = std::max(cnt[u][i], cnt[v][i]);
            }
        }
        cnt[u][s[u] - 'a']++;
        vis[u] = 0;
    };
    
    for (int i = 0; i < n; i++) {
        if (!g[i]) {
            dfs(dfs, i);    
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            ans = std::max(cnt[i][j], ans);
        }
    }
    std::cout << ans << "\n";
}