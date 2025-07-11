#include<bits/stdc++.h>

using ll = long long;

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
    int n, m, k;
    std::cin >> n >> m >> k;

    std::string s;
    std::cin >> s;
    s = '0' + s;

    for (int i = 0; i <= n; i++) {
        s[i] = s[i] - '0';
    }

    std::vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = s[i] + pre[i - 1]; 
    }

    std::vector<int> nxt(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == 0) {
            nxt[i] = i;
        } else {
            nxt[i] = nxt[i - 1];
        }
    }

    auto check = [&](int o) {
        std::vector dp(n + 1, std::vector<int>(k + 1, inf));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = o; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                int ni = std::max(0, nxt[i - o] - 1);
                dp[i][j] = std::min(dp[i - 1][j], dp[ni][j - 1] + o - (pre[i] - pre[i - o]));
            }
        }

        return dp[n][k] <= m;
    };

    int l = 1, r = n;
    int ans = -1;
    while(l <= r) {
        int mid = l + r >> 1;

        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    std::cout << ans << "\n";
}