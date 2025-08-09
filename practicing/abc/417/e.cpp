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
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;

    x--;
    y--;
    std::vector g(n, std::vector<int>(n));
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        g[u][v] = g[v][u] = 1;
    }

    std::vector<int> vis(n);
    std::vector<int> ans;

    bool ok = false;
    auto dfs = [&](auto &&self, int s) -> void {
        vis[s] = 1;
        ans.push_back(s);
        if (s == y) {
            ok = true;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] || !g[s][i] ) {
                continue;
            }
            self(self, i);
            if (ok) {
                return;
            }
        }
        if (ok) {
            return;
        }
        ans.pop_back();
    };

    dfs(dfs, x);
    for (auto o : ans) {
        std::cout << o + 1 << " \n"[o == ans.back()];
    }
}