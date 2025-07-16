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
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> a(n * m);
    for (int i = 0; i < n * m; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    std::ranges::sort(a);

    auto cmp = [&](auto x, auto y) {
        if (x.first != y.first) {
            return x.first < y.first;
        }
        return x.second > y.second;
    };

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        std::ranges::sort(a.begin() + i * m, a.begin() + i * m + m, cmp);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < j; k++) {
                if (a[i * m + k].second < a[i * m + j].second) {
                    ans++;
                }
            }
        }
    }

    std::cout << ans << "\n";
}