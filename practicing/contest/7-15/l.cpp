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

    std::vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) {
        std::cin >> a[i];
    }

    std::vector<int> c(m + 1);
    for (int i = 1; i <= m; i++) {
        c[i] = i;
    }

    std::sort(c.begin(), c.end(), [&](auto x , auto y) {
        if (a[x] != a[y]) {
            return a[x] < a[y];
        } else {
            return x > y;
        }
    });

    for (int i = 1; i <= m; i++) {
        std::cout << c[i] << " "[i == m];
    }

    ll ans = 0;
    std::vector<ll> tr(m+ 1);

    auto lowbit = [&](int x) {
        return x & (-x);
    };

    auto add = [&](int p) -> void {
        for (int i = p; i <= m; i += lowbit(i)) {
            tr[i]++; 
        }
    };

    auto query = [&](int p) {
        ll res = 0;
        for (int i = p; i >= 1; i -= lowbit(i)) {
            res += tr[i];
        }
        return res;
    };

    for (int i = 1; i <= m; i++) {
        ans += query(c[i] - 1);
        add(c[i]);
    }

    std::cout << ans << "\n";
}