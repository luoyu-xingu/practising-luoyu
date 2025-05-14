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
    //std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n;
    std::cin >> n;
    
    std::vector e(n + 1, std::vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    std::vector<int> dfn(n + 1), lson(n + 1), len(n + 1), fa(n + 1);
    auto dfs1 = [&](this auto&& self, int u, int f) -> void {
        for (auto v : e[u]) {
            if (v == f) {
                continue;
            }
            fa[v] = u;
            self(v, u);
            if (len[v] > len[lson[u]]) {
                lson[u] = v;
            }
        }
        
        len[u] = len[lson[u]] + 1;
    };
    dfs1(1, 1);

    std::vector<int> ans(n + 1), dp(n + 1);
    int cnt = 0;
    auto dfs2 = [&](this auto &&self, int u) -> void {
        dfn[u] = ++cnt;
        dp[dfn[u]] = 1;

        if (lson[u] == 0) {
            return;
        }

        self(lson[u]);

        for (auto v : e[u]) {
            if (v == fa[u] || v == lson[u]) {
                continue;
            }
            self(v);
        }

        ans[u] = ans[lson[u]] + 1;
        if (dp[dfn[u] + ans[u]] == 1) {
            ans[u] = 0;
        }
        
        for (auto v : e[u]) {
            if (v == fa[u] || v == lson[u]) {
                continue;
            }

            for (int i = 1; i <= len[v]; i++) {
                dp[dfn[u] + i] += dp[dfn[v] + i - 1];
                if (dp[dfn[u] + i] > dp[dfn[u] + ans[u]] || (dp[dfn[u] + i] == dp[dfn[u] + ans[u]] and i < ans[u])) {
                    ans[u] = i;
                } 
            }
        }

/*         if (dp[dfn[u] + ans[u]] == 1) {
            ans[u] = 0;
        } */
    };
    dfs2(1);

    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << "\n";
    }
}
