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
    int n;
    std::cin >> n;

    std::vector<int> c(n + 1);
    std::vector<std::vector<int>> rc(n + 1); 
    for (int i = 1; i <= n; i++) {
        std::cin >> c[i];
        rc[c[i]].push_back(i);
    }

    std::vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];
    }

    std::vector<ll> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        if (rc[i].size() == 0) {
            ans[i] = w[i] + n;
            continue; 
        }

        int l = rc[i][0];
        bool ok = false;
        if (l != 1) {
            ans[i] += w[i] + l - 1;
            ok = true;
        }
        for (int j = 1; j < rc[i].size(); j++) {
            if (rc[i][j] == rc[i][j - 1] + 1) {
                continue;
            }
            int q = rc[i][j] - rc[i][j - 1] - 1;
            if (!ok) {
                ans[i] += q + w[i];
                ok = true;
            } else {
                ans[i] += q + std::min(w[i], rc[i][j - 1] - l + 1);
            }
            l = rc[i][j];
        }

        //std::cout << ans[i] << " \n"[i == n];
        if (rc[i].back() != n) {
            int q = n - rc[i].back();
            if (!ok) {
                ans[i] += q + w[i];
            } else {
                ans[i] += std::min(w[i], n - l + 1);
            }
        }
    }

    
    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] <<  " \n"[i == n];
    }
}