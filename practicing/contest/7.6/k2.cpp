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
    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 2>> ans;
    auto push = [&](int x,  int y) {
        ans.push_back({x + 1, y + 1});
    };


    std::vector<std::vector<int>> e(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
    }

    std::vector<int> d(n), g(n, -1);
    for (int i = 0; i < n; i++) {
        d[i] = e[i].size();
    }

    std::vector<int> vis(n);
    int a;
    auto dfs = [&](auto &&self, int x) -> void {
        vis[x] = 1;
        for (auto y : e[x]) {
            d[y]--;
        }

        a++;
        while (d[x] != 0) {
            int z = p[a];

            for (auto y : e[z]) {
                g[y] = z;
            }

            if (g[x] != z) {
                push(x, z);
            }

            self(self, z);
        }

    };

    for (a = 0; a < n;) {
        if (vis[p[a]]) {
            continue;
        }
        dfs(dfs, p[a]);
    }

    std::cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        std::cout << x << " " << y << "\n";
    }
}