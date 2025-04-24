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
    while(t--) solve();
    return 0;
}
void solve(){
    int n, m;
    std::cin >> n >> m;
    std::vector e(m, std::array<int, 3>());
    std::vector<int> fa(n + 1);
    std::iota(fa.begin(), fa.end(), 0);

    auto find = [&](auto &&self, int x) {
        if(x == fa[x]) return x;
        return fa[x] = self(self, fa[x]);
    };

    for(int i = 0; i < m; i++) {
        std::cin >> e[i][1] >> e[i][2] >> e[i][0];
    }
    std::vector eg(n + 1, std::vector<std::pair<int, int>>());
    std::sort(e.begin(), e.end(), std::greater<std::array<int, 3>>());
    for(int i = 0; i < m; i++) {
        auto [z, x, y] = e[i];
        x = find(find, x);
        y = find(find, y);
        if(x != y) {
            fa[x] = y;
            eg[e[i][1]].emplace_back(e[i][2], z);
            eg[e[i][2]].emplace_back(e[i][1], z);
        }
    }
    int q = log2(n);
    std::vector stp(n + 1, std::vector<int>(q + 1));
    std::vector stmin(n + 1, std::vector<int>(q + 1, inf));
    std::vector<int> dep(n + 1); 
    std::vector<char> vis(n + 1);
    auto dfs = [&](auto &&self, int u, int f, int cnt = 1) ->void {
        vis[u] = 1;
        for(auto [v, w] : eg[u]) {
            if(v == f) {
                continue;
            }
            dep[v] = cnt + 1;
            stp[v][0] = u, stmin[v][0] = w;
            for(int j = 1; (1 << j) <= dep[v]; j++) {
                stp[v][j] = stp[stp[v][j - 1]][j - 1];
                stmin[v][j] = std::min(stmin[v][j - 1], stmin[stp[v][j - 1]][j - 1]);
            }
            self(self, v, u, cnt + 1);
        }
    };

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(dfs,i, 0);
        }
    }
    auto lca = [&](int x, int y) {
        if(find(find, x) != find(find, y)) {
            return -1;
        } 

        if(dep[x] < dep[y]) {
            std::swap(x, y);
        }
        int min = inf;
        if(dep[x] != dep[y]) {
            int k = dep[x] - dep[y];
            for(int i = q; i >= 0; i--) {
                if((1 << i) & k) {
                    k -= (1 << i);
                    min = std::min(min, stmin[x][i]);
                    x = stp[x][i];
                }
            }
        }
        if(x == y) return min;
        for(int i = q; i >= 0; i--) {
            if(stp[x][i] != stp[y][i]) {
                min = std::min(min, std::min(stmin[x][i], stmin[y][i]));
                x = stp[x][i];
                y = stp[y][i];
            }
        }
        return std::min(min, std::min(stmin[x][0], stmin[y][0]));
    };
    int p;
    std::cin >> p;
    while(p--) {
        int x, y;
        std::cin >> x >> y;
        std::cout << lca(x, y) << '\n';
    }
}