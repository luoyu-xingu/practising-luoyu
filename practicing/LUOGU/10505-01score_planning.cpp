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

    //std::cout << std::fixed << std::setprecision(15);

    int t = 1;
//    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n, k;

    while(std::cin >> n >> k) {
        if (n == 0 and k == 0) {
            return ;
        }
        k = n - k;

        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            std::cin >> b[i];
        }

        double l = 0, r = 1e12;

        auto check = [&](double x) {
            std::vector<double> c(n);
            for (int i = 0; i < n; i++) {
                c[i] = 1.0 * a[i] - x * b[i];
            }

            std::sort(c.begin(), c.end(), std::greater<double>());
            double ans = 0;
            for (int i = 0; i < k; i++) {
                ans += c[i];
            }

            return ans >= 0;
        };

        for (int i = 0; i < 100; i++) {
            double mid = (l + r) / 2.00;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }

        std::cout << (int)(100 * l + 0.5) << "\n";
    } 
}
