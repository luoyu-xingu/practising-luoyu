#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

int dis[105][16][16][100][10];
int vis[105][16][16][100][10];

class Info {
    public:
    int z, x, y;
    int nb, nr;
    Info(int z, int x, int y, int nb, int nr) : x(x), y(y), z(z), nb(nb), nr(nr) {}
};
const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(15);

    int t = 1;
//    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<std::string>> a(n + 1, std::vector<std::string>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
            a[i][j] = ' ' + a[i][j];
        }
    } 

    //01bfs
    {   int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= m; k++) {
                    for (int x = 0; x <= 99; x++) {
                        for (int y = 0; y <= 9; y++) {
                            dis[i][j][k][x][y] = inf;
                        }
                    }
                }
            }
        }
        //return;
        int x, y, z;
        auto find = [&]() {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    for (int k = 1; k <= m; k++) {
                        if (a[i][j][k] == 'P') {
                            x = j, y = k, z = i;
                            return ;
                        }
                    }
                }
            }
        };
        find();
        dis[z][x][y][0][0] = 0;
        //std::cout << z << " " << x << " "  << y << "\n";
        //return;
        std::deque<Info> dq;
        dq.emplace_back(z, x, y, 0, 0);
        vis[z][x][y][0][0] = 1;
        while(!dq.empty()) {
            cnt++;
            //if (cnt >= 100) {
            //    return;
            //}
            //assert(cnt < 100);
            auto [z, x, y, b, r] = dq.front();
            dq.pop_front();
            //vis[z][x][y][b][r] = 1;  
            //std::cout << z << " " << x << " " << y << " " << b << " " << r << "\n";
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z;
                if (nx <= 0 || nx > m || ny <= 0 || ny > m || nz <= 0 || nz > n) {
                    continue;
                }
                if (vis[nz][nx][ny][b][r]) {
                    continue;
                }    

                if (a[nz][nx][ny] == 'U') {
                    if(vis[nz + 1][nx][ny][b][r]) {
                        continue;
                    }
                    dis[nz + 1][nx][ny][b][r] = dis[z][x][y][b][r];
                    vis[nz + 1][nx][ny][b][r] = 1;
                    dq.emplace_front(nz + 1, nx, ny, b, r);
                } 

                if (a[nz][nx][ny] == 'D') {
                    if(vis[nz - 1][nx][ny][b][r]) {
                        continue;
                    }
                    dis[nz - 1][nx][ny][b][r] = dis[z][x][y][b][r];
                    vis[nz - 1][nx][ny][b][r] = 1;
                    dq.emplace_front(nz - 1, nx, ny, b, r);
                }

                if (a[nz][nx][ny] == '.' || a[nz][nx][ny] == 'U' || a[nz][nx][ny] == 'D') {
                    if (vis[nz][nx][ny][b][r]) {
                        continue;
                    }
                    dis[nz][nx][ny][b][r] = dis[z][x][y][b][r];
                    vis[nz][nx][ny][b][r] = 1;
                    dq.emplace_front(nz, nx, ny, b, r);
                } else if (a[nz][nx][ny] == '#') {
                    continue; 
                } else if (a[nz][nx][ny] == 'R') {
                    if (r + 1 > 9) {
                        continue;
                    }
                    if (vis[nz][nx][ny][b][r + 1]) {
                        continue;
                    }
                    dis[nz][nx][ny][b][r + 1] = dis[z][x][y][b][r];
                    vis[nz][nx][ny][b][r + 1] = 1;
                    dq.emplace_front(nz, nx, ny, b, r + 1);
                } else if (a[nz][nx][ny] == 'B') {
                    if (b + 1 > 99) {
                        continue;
                    }
                    if (vis[nz][nx][ny][b + 1][r]) {
                        continue;
                    }
                    dis[nz][nx][ny][b + 1][r] = dis[z][x][y][b][r];
                    vis[nz][nx][ny][b + 1][r] = 1;
                    dq.emplace_front(nz, nx, ny, b + 1, r);
                } else if (a[nz][nx][ny] == 'Y'){
                    //std::cout << "~~~~~~~~~\n";
                    if (vis[nz][nx][ny][b][r]) {
                        continue;
                    }
                    dis[nz][nx][ny][b][r] = dis[z][x][y][b][r] + 1;
                    vis[nz][nx][ny][b][r] = 1;
                    dq.emplace_back(nz, nx, ny, b, r);
                }

            }
        }
    }

    while(q--) {
        int h, x, y, ny, nb, nr;
        std::cin >> h >> x >> y >> ny >> nb >> nr;

        bool ok = false;
        //std::cout << dis[h][x][y][1][0] << "\n";
        for (int i = 0; i <= std::min(nb, 99); i++) {
            for (int j = 0; j <= std::min(nr, 9); j++) {
                if (dis[h][x][y][i][j] <= ny) {
                    ok = true;
                }
            }
        }

        std::cout << (ok ? "YES\n" : "NO\n");
    }
}