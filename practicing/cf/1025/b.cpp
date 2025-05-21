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
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    if (n > m) {
        std::swap(n, m);
        std::swap(a, b);
    }

    int m2 = std::min(m - b + 1, b);
    //std::cout << n << " " << m <<"\n";
    auto cal = [&](int x) -> int {
        return ceil(std::log2(x));
    };

    int ans = 1;
    ans += cal(n);
    ans += cal(m2);
    //std::cout << ans << "\n";;

    int n2 = std::min(n - a + 1, a);

    ans = std::min(ans, 1 + cal(n2) + cal(m));
    std::cout << ans << "\n";
}