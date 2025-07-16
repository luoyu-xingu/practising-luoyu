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

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector e(n + 1, std::vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::vector<int> vis(n + 1);
    std::vector<std::vector<int>> o;
    auto dfs = [&](auto &&self, int u) -> void {
        vis[u] = 1;
        for (auto v : e[u]) {
            if (!vis[v]) {
                o[o.size() - 1].push_back(v);
                self(self, v);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            o.push_back(std::vector<int>());
            o[o.size() - 1].push_back(i);
            dfs(dfs, i);
        }
    }

/*     for (int i = 0; i < o.size(); i++) {
        for (int j = 0; j < o[i].size(); j++) {
            std::cout << o[i][j] << " \n"[j == o[i].size() - 1];
        }
    }  */

    std::vector<int> ans(n + 1);
    std::vector<std::vector<int>> tmp;  
    for (auto q : o) {
        tmp.push_back(std::vector<int>());
        for (auto x : q) {
            tmp[tmp.size() - 1].push_back(a[x]);
        }
    }

    for (int i = 0; i < tmp.size(); i++) {
        std::sort(tmp[i].begin(), tmp[i].end(), std::greater<int>());
        std::sort(o[i].begin(), o[i].end());
    }


    for (int i = 0; i < o.size(); i++) {
        for (int q = 0; q < o[i].size(); q++) {
            ans[o[i][q]] = tmp[i][q];
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
        assert(ans[i] != 0);
    }
}