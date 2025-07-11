// 100000000

#include<bits/stdc++.h>
using ll = long long;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
ll dp[405][405];
void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = Inf;
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    std::vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    // l, r
    for (int l = n; l >= 1; l--) {
        for (int r = l + 1; r <= n; r++) {
            for (int k = l; k <= r && k <= n; k++) {
                dp[l][r] = std::min(dp[l][r], dp[l][k] + dp[k + 1][r] + pre[r] - pre[l - 1]);
            }
        }
    }

    std::cout << dp[1][n] << "\n";

}