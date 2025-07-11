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
    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> t(n + 1), l(n + 1), w(n + 1);

    for (int i = 1; i <= n; i++) {
        std::cin >> t[i] >> l[i] >> w[i];
    }

    ll ans = -1;

    ll lp = 0, r = 4e18;

    auto check = [&](ll o) {
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            res += o / (1LL * t[i] * l[i] + w[i]) * l[i];
            ll p = o % (1LL * t[i] * l[i] + w[i]);
            if (p / t[i] >= l[i]) {
                res += l[i];
            } else {
                res += p / t[i];
            }

            if (res >= k) {
                return true;
            }
        }
        return res >= k;
    };


    while(lp <= r) {
        ll mid = lp + (r - lp) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            lp = mid + 1;
        }
    }

    assert(ans != -1);
    std::cout << ans << "\n";



}