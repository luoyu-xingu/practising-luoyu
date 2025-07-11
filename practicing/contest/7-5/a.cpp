#include<bits/stdc++.h>

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

    std::vector<int> dp(n + 1);
    dp[1] = 0;
    dp[2] = std::abs(a[2] - a[1]);

    for (int i = 3; i <= n; i++) {
        dp[i] = std::min(dp[i - 1] + std::abs(a[i - 1] - a[i]), dp[i - 2] + std::abs(a[i] - a[i - 2]));
    }

    std::cout << dp[n] << "\n";
}