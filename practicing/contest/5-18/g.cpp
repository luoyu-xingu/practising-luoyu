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
//    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n ;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] % 2 == 0) {
            ans += a[i] / 2;
            a[i] = 0;
        } else {
            ans += (a[i] - 1) / 2;
            a[i] = 1;
        }
        ans += std::min(a[i], a[i + 1]);
        int q = std::min(a[i], a[i + 1]);
        a[i] -= q;
        a[i + 1] -= q;
    }

    ans += a[n] / 2;

    std::cout << ans << "\n";
}