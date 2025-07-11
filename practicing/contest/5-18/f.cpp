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
    int h, w, k;
    std::cin >> h >> w >> k;

    int s, e;
    std::cin >> s >> e;

    std::vector<std::vector<int>> a(h + 1, std::vector<int>(w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            std::cin >> a[i][j];
        }
    }

    ll ans = 1LL * a[s][e] * k;

    std::vector<std::vector<char>> vis(h + 1, std::vector<char>(w + 1));
    vis[s][e] = 1;
    auto dfs = [&](auto &&self, int x, int y, int m, ll sum = 0) -> void{
        //std::cout << x << " " << y << "\n";

        //ans = std::max(1LL * a[x][y] * m, ans);
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] < 1 || x + dx[i] > h || y + dy[i] < 1 || y + dy[i] > w || vis[x + dx[i]][y + dy[i]]) {
                continue;
            }
            if (m >= 0) {
                ans = std::max(1LL * a[x][y] * m + sum, ans);
            }
            vis[x + dx[i]][y + dy[i]] = 1;
            self(self, x + dx[i], y + dy[i], m - 1, sum + a[x + dx[i]][y + dy[i]]);
        }
    };

    dfs(dfs, s, e, k, 0);
    std::cout << ans << "\n";
}