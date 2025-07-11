#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;
#define int long long
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
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::ranges::sort(a);

    std::vector<int> b(n + 1);
    for (int i = 0; i < n; i++) {
        b[std::lower_bound(a.begin(), a.end(), a[i]) - a.begin()]++;
    }

    std::vector<std::array<int, 3>> ans;


    auto check = [&](int o) {
        ll res = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] > o) {
                res += o - b[i];
            }
            res += b[i];
        }

        return res >= 3 * o;
    };

    int l = 0, r = n / 3;
    int res = 0;
    while(l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }

    std::vector<int> c;
    for (int i = 0; i < n; i++) {
        if (i > 0 and a[i] == a[i - 1]) {
            continue;
        }
        for (int j = 1; j <= std::min(b[i], res); j++) {
            c.push_back(a[i]);
        }
    }

    auto push = [&](int x, int y, int z) {
        ans.push_back({c[x], c[y], c[z]});
    };

    for (int i = 1; i <= res; i++) {
        push(i - 1, i - 1 + res, i - 1 + 2 * res);
    }
    //std::cout << res << "\n";
    std::cout << ans.size() << "\n";
    for (auto [x, y, z] : ans) {
        std::cout << z << " " << y << " " << x << "\n";
    }

}