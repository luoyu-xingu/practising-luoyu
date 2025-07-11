#include<bits/stdc++.h>

const double pi = atan2(0,-1);
void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(10);

    int t = 1;
    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n, k;
    std::cin >> n >> k;

    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
    }

    std::vector<double> x(n);
    for (int i = 0; i < n; i++) {
        x[i] = atan2(1.0 * a[i][1], 1.0 * a[i][0]);
    }

    std::sort(x.begin(), x.end());

    auto cal = [&](int a, int b) {
        auto res = x[b] - x[a];
        if (b <= a) {
            res += 2 * pi;
        }
        return res;
    };

    double max = 0;
    for (int i = 0; i < n; i++) {
        max = std::max(max, cal(i, (i + k) % n));
    }

    std::cout << max << "\n";
}