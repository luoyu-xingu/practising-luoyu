#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    int m, x;
    std::cin >> m >> x;

    std::vector<int> c(m + 1), h(m + 1);
    for (int i = 1; i <= m; i++) {
        std::cin >> c[i] >> h[i];
    }

    int sum = std::accumulate(h.begin(), h.end(), 0);

    std::vector dp(m + 1, std::vector<std::pair<bool, ll>>(sum + 1, {false, 0LL}));

    dp[0][0].first = 1;
    dp[0][0].second = 0;

    for (int i = 0; i <= sum; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < j; k++) {
                if (i >= h[j]) {
                    if (dp[k][i - h[j]].first && dp[k][i - h[j]].second + 1LL * (j - k - 1) * x>= c[j]) {
                        dp[j][i].second = std::max(dp[j][i].second, dp[k][i - h[j]].second + 1LL * (j - k - 1) * x - c[j] + x);
                        dp[j][i].first = 1;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= sum; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[j][i].first) {
                ans = i;
            }
        }
    }

    std::cout << ans << "\n";
}