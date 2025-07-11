#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};
struct Point {
    int x, y, z;
};
const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(15);

    int t = 1;
    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n;
    std::cin >> n;

    std::vector<Point> p(n);
    int maxx = -1, maxy = -1, maxz = -1;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i].x >> p[i].y >> p[i].z;
        maxx = std::max(maxx, p[i].x);
        maxy = std::max(maxy, p[i].y);
        maxz = std::max(maxz, p[i].z);
    }

    std::vector<int> X(maxx + 1), Y(maxy + 1), Z(maxz + 1);

    for (int i = 0; i < n; i++) {
        X[p[i].x]++;
        Y[p[i].y]++;
        Z[p[i].z]++;
    }

    std::vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        cnt[i] = std::max({X[p[i].x], Y[p[i].y], Z[p[i].z]}) - 1;
    }

    std::vector<int> ans(n + 1);
    for (int i = 0; i < n; i++) {
        if (cnt[i] < n) {
            ans[cnt[i] + 1]++;
        }
    }

    for (int i = 1; i < n; i++) {
        ans[i] += ans[i - 1];
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}