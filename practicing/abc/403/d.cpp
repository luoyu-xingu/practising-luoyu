#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 7;
void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
//    std::cin >> t;
    while(t--) solve();
    return 0;
}
void solve(){
    int n, d;
    std::cin >> n >> d;

    std::vector<int> a(n);
    std::vector<int> D(N);
    std::vector<int> vis(N);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        D[a[i]]++;
        vis[a[i]] = 1;
    }
//10 3
//1 6 2 10 2 3 2 10 6 4
    //std::sort(a.begin(), a.end());
    int ans = 0;
    int max = *std::max_element(a.begin(), a.end());
    int min = *std::min_element(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (!vis[a[i]]) {
            continue;
        } 

        std::vector<int> c;
        int p = a[i];
        assert(D[a[i]]);
        while (p <= max and D[p]) {
            vis[p] = 0;
            c.push_back(D[p]);
            p += d;
        }  
        p = a[i] - d;
        while (p >= min and D[p]) {
            vis[p] = 0;
            c.push_back(D[p]);
            p -= d;
        }  
        auto cal = [&]() {
            //if(c.size() == 0) return 0;
            if  (c.size() == 1) {
                return 0;
            }

            std::vector<std::array<int, 2>> dp(c.size());

            dp[0][1] = 0;
            dp[0][0] = c[0];
            int res = 0;
            for(int i = 1; i < c.size(); i++) {
                dp[i][1] = dp[i - 1][0];
                dp[i][0] = c[i] + std::min(dp[i - 1][1], dp[i - 1][0]);
            }
            res = std::min(dp[c.size() - 1][0], dp[c.size() - 1][1]);
            return res;
        };

        ans += cal();
    }
    std::cout << ans << "\n";
}