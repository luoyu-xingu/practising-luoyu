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
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto f = [&]() {
        std::vector<int> c(n + 1);
        int mad = 0;
        for (int i = 0; i < n; i++) {
            if (c[a[i]]) {
                mad = std::max(a[i], mad);
            }
            c[a[i]] = 1;
            a[i] = mad;
        }
    };

    ll ans = std::accumulate(a.begin(), a.end(), 0LL);

    f();

    ans += std::accumulate(a.begin(), a.end(), 0LL);

    f();

    for (int i = 0; i < n; i++) {
        ans += 1LL * (n - i) * a[i];
    }

    std::cout << ans << "\n";
}