#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;
const int MAXV = 1000;
void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
//    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> p(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i] >> a[i] >> b[i];
    }

    std::vector dp(n + 1, std::vector<int>(MAXV + 1));
    for (int i = 0; i <= MAXV; i++) {
        dp[n][i] = i;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= MAXV; j++) {
            if (p[i] >= j) {
                dp[i][j] = dp[i + 1][j + a[i]];
            } else {
                dp[i][j] = dp[i + 1][std::max(0, j - b[i])];
            }
        }
    }

    std::vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1] + b[i - 1];
    }

    int q;
    std::cin >> q;
    while (q--) {
        int x;
        std::cin >> x;
        auto it = std::lower_bound(pre.begin(), pre.end(), x - MAXV) - pre.begin();
        if (it == n + 1) {
            std::cout << x - pre[n] << "\n";
        } else {
            std::cout << dp[it][x - pre[it]] << "\n";
        }
    }
}