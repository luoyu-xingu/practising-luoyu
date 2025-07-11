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
    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;

    ll ans = 0;
    if (x <= y) {
        ans = 1LL * (n + m) * y;
        std::cout << ans << "\n";
        return;
    }


    if (x <= 1LL * y * n) {
        ans += 1LL * y * (n + m);
    } else {
        if (x <= 1LL * y * (n + m)) {
            ans += ((n == 0) ? 0 : x) + 1LL * y * m;
        } else {
            ans = (n == 0 || m == 0) ? 0 : x;
        }
    }

    std::cout << ans << '\n';
}