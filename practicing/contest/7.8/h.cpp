#include<bits/stdc++.h>

using ll = long long;
#define int long long
const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    //std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = n - 1; i >= 0; i--) {
        std::cin >> a[i];
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m + 1; j++) {
            b[i] += a[i][j] - '0'; 
        }
    }

    for (int i = 1; i < n; i++) {
        b[i] += b[i - 1];
    }

    if (b[n - 1] == 0) {
        std::cout << 0 << "\n";
        return;
    }


    ll l = 0, r = m + 1;
    int ld = m + 1, rd = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m + 2; j++) {
            if (a[i][j] == '1') {
                rd = j;
            }
        }

        for (int j = m + 1; j >= 0; j--) {
            if (a[i][j] == '1') {
                ld = j;
            }
        }

        //std::cout << rd << " " << ld << "\n";

        if (i == 0) {
            r = m + 1;
            l = 2 * rd; 
            if (b[n - 1] - b[i] != 0) {
                l++;
                r++;
            } else {
                l = rd;
                r = Inf;
                break;
            }
        } else if (i != n - 1 and b[n - 1] - b[i] != 0){
            auto l1 = l, r1 = r;
            l = std::min(r1 + m + 1, l1 + 2 * rd) + 1;
            r = std::min(l1 + m + 1, r1 + 2 * (m + 1 - ld)) + 1;
        } else {
            l += rd;
            r += (m + 1 - ld);
            break;
        }
        rd = 0, ld = m + 1;
    }
    //std::cout << l << " " << r << "\n";
    std::cout << std::min(l, r) << "\n";
}
