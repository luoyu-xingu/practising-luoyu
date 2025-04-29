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
    //std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;
    s = ' ' + s;

    std::vector<std::vector<int>> nxt(n + 2, std::vector<int>(k));
    std::vector<int> dp(n + 1, inf);
    dp[n + 1] = 0;
    for (int i = 0; i < k; i++) {
        nxt[n + 1][i] = n + 1;
    }

    std::vector<int> lst(k, n + 1);

    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < k; j++) {
            nxt[i][j] = lst[j];
            dp[i] = std::min(dp[i], dp[nxt[i][j]] + 1);
        }
        if (i) {
            lst[s[i] - 'a'] = i; 
        }
    }

    int q;
    std::cin >> q;

    while (q--) {
        std::string t;
        std::cin >> t;
        int x = 0;
        for (auto c : t) {
            x = nxt[x][c - 'a'];
        }
        std::cout << dp[x] << "\n";
    }
}