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
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<ll> pre(n + 1);
    std::vector<ll> dp(n + 2);

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = n; i >= 1; i--) {
        int l = i, r = n;
        int res = -1;

        while(l <= r) {
            int mid = (l + r) >> 1;
            if (pre[mid] - pre[i - 1] > x) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        //std::cout <<res << "\n";
        if (res != -1) {
            dp[i] = 1 + dp[res + 1];
        }
    }

    std::cout << 1LL * n * (n + 1) / 2 - std::accumulate(dp.begin(), dp.end(), 0LL) << "\n";

    
}