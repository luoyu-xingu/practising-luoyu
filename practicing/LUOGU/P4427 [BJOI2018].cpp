#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
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

    std::vector<std::vector<int>> e(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    std::vector<std::vector<ll>> dep(51, std::vector<ll> (n + 1, -1));
    std::vector<std::array<int, 20>> st(n + 1);
    auto dfs = [&](auto &&self, int u = 1, int f = 0) -> void {
        dep[1][u] = dep[1][f] + 1;
        for (int i = 2; i <= 50; i++) {
            dep[i][u] = dep[i - 1][u] * dep[1][u] % mod;
        }

        st[u][0] = f;
        for (int i = 1; (1 << i) <= dep[1][u]; i++) {
            st[u][i] = st[st[u][i - 1]][i - 1];
        }

        for (auto v : e[u]) {
            if (v == f) {
                continue;
            }

            self(self, v, u);
        }
    };

    dfs(dfs);

    for (int i = 1; i <= n; i++) {
        dep[0][i] = dep[1][i];
    }

    auto lca = [&](int x, int y) {
        if (dep[0][x] < dep[0][y]) {
            std::swap(x, y);
        }

        int k = dep[0][x] - dep[0][y];

        if (k) {
            for (int i = 19; i >= 0; i--) {
                if (k >> i & 1) {
                    x = st[x][i];
                    k -= 1 << i;
                }
            }
        }

        if (x == y) {
            return y;
        }

        for (int i = 19; i >= 0; i--) {
            if (st[x][i] != st[y][i]) {
                x = st[x][i];
                y = st[y][i];
            }
        }
        return st[x][0];
    };

    auto Set = [&](auto &&self, int u, int f) -> void {
        for (auto v : e[u]) {
            if (v == f) {
                continue;
            }

            for (int i = 1; i <= 50; i++) {
                dep[i][v] += dep[i][u];
                dep[i][v] %= mod;
            }

            self(self, v, u);
        }
    };

    Set(Set, 1, 1);

/*     for (int i = 1; i <= n; i++) {
        std::cout << dep[5][i] << "\n";
    } */
    int m;
    std::cin >> m;
    while(m--) {
        int x, y, k;
        std::cin >> x >> y >> k;
        int L = lca(x, y);
        ll ans = dep[k][x] - dep[k][L] + mod + dep[k][y];
        //std::cout << ans << "\n";
        if (L != 1) {
            ans -= dep[k][st[L][0]];
            ans += mod;
            ans %= mod;
        }
        ans %= mod;
        std::cout << ans << "\n";
    }

}
