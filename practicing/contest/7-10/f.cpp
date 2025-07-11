#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

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
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) {
        std::cin >> a[i];
    }

    std::vector<ll> dp(m + 1);
    for (int i = 1; i <= m; i++) {
        dp[i] = a[i];
        ll min = Inf;
        for (int j = i - 1; j >= 0 && j >= i - 500; j--) {
            min = std::min(min, dp[j] + 1LL * (i - j) * (i - j) * (i - j) * (i - j));
        }
        dp[i] += min;
    }

    std::cout << dp[m] << "\n";
}

/*1 0
2 1
3 2
4 3
5 4
6 5
7 6
8 7
9 8
10 9
11 10
12 11
13 12
14 13
15 14
16 14
17 15
18 16
19 17
20 18
221*/

/*1 0
2 1
3 2
4 3
5 4
6 5
7 6
8 7
9 8
10 9
11 10
12 11
13 12
14 13
15 13
16 14
17 15
18 16
19 17
20 18
221
*/

