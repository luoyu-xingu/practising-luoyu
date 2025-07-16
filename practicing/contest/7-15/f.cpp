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
    std::vector<int> f(n + 1);
    int o = 1;
    while ((o << 1) <= n) {
        o <<= 1;
    }
    
    assert(o <= n);
    for (int i = 2; i <= n; i += 2) {
        f[i] = 1;
    }

    for (int i = 3; i <= o; i += 2) {
        for (int j = 0; (1 << j) <= o; j++) {
            if (((i >> j) & 1) == 0) {
                f[i] = (1 << j);
                break;
            }
        }
    }

    ll ans = 0;
    for (int i = o + 1; i <= n; i += 2) {
        bool ok = false;
        for (int j = 0; (1 << j) <= o; j++) {
            if (((i >> j) & 1) == 0) {
                f[i] = (1 << j);
                ok = true;
                break;
            }
        }
        if (!ok) {
            ans++;
            f[i] = 1;
        }
    }
    assert(ans == 0 || ans == 1);
    std::cout << ans << "\n";
    for (int i = 2; i <= n; i++) {
        assert(f[i] != 0);
        std::cout << f[i] << " \n"[i == n];
    }
}