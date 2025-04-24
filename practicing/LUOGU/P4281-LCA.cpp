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
    std::vector e(n + 1, std::vector<int>());
    for(int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    std::vector<int> dep(n + 1);
    int q = log2(n);
    std::vector st(n + 1,std::vector<int>(q + 1));
    auto dfs = [&](auto &&self, int u, int fa, int cnt = 1) -> void {
        dep[u] = cnt;
        st[u][0] = fa;
        for(int i = 1; (1 << i) <= dep[u]; i++) {
            st[u][i] = st[st[u][i - 1]][i - 1];
        } 
        for(auto v : e[u]) {
            if(v == fa) continue;
            self(self, v, u, cnt + 1);
        }
    };
    dfs(dfs, 1, 0);
    auto lca = [&](int x, int y) {
        if(dep[x] < dep[y]) {
            std::swap(x, y);
        }
        if(dep[x] != dep[y]) {
            int k = dep[x] - dep[y];
            for(int i = q; i >= 0; i--) {
                if(k & (1 << i)) {
                    k -= (1 << i);
                    x = st[x][i];
                }
            }
        }
        if(x == y) return x;
        for(int i = q; i >= 0 ; i--) {
            if(st[x][i] != st[y][i]) {
                x = st[x][i];
                y = st[y][i]; 
            } 
        }
        return st[x][0];
    };
    while(m--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        auto l1 = lca(a, b), l2 = lca(a, c), l3 = lca(b, c);
        int lo = (l1 != l2) ? ((dep[l1] > dep[l2])? l1 : l2) : l3;
        int hi = (l1 != l2) ? ((dep[l1] > dep[l2]) ? l2 : l1) : l1;
        // 三个点最多两个lca, 并且如果有两个 那么 更高的的lca 一定占据两个的lca
        int ans = dep[a] + dep[b] + dep[c] - 2 * dep[hi] - dep[lo];
        std::cout << lo << ' ' << ans << '\n'; 
    } 
}