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
    int h, w, n, m;
    std::cin >> h >> w >> n >> m;

    std::vector vis(w, std::vector<char>(h));
    auto dfs = [&](auto &&self, int x, int y, int r, int c) {
        if (r == w) {
            return 1LL;
        }
        
        int nr, nc;
        if (c == h - 1) {
            nr = r + 1;
            nc = 0;
        } else {
            nr = r;
            nc = c + 1;
        }
        if (vis[r][c]) {
            return self(self, x, y, nr, nc);
        }

        ll ans = 0;
        if (y != 0) {
            vis[r][c] = 1;
            ans += self(self, x, y - 1, nr, nc);
            vis[r][c] = 0;
        }

        if (x and c + 1 < h and !vis[r][c + 1]) {
            vis[r][c] = 1;
            vis[r][c + 1] = 1;
            ans += self(self, x - 1, y, nr, nc);
            vis[r][c] = 0;
            vis[r][c + 1] = 0;
        }

        if (x and r + 1 < w and !vis[r + 1][c]) {
            vis[r][c] = 1;
            vis[r + 1][c] = 1;
            ans += self(self, x - 1, y, nr, nc);
            vis[r][c] = 0;
            vis[r + 1][c] = 0;
        }
        return ans;
    };

    std::cout << dfs(dfs, n, m, 0, 0) << "\n";
}