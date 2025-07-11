#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
//    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    int n, m, t;
    std::cin >> n >> m >> t;

    auto C = [&](int x, int y) {
        if (x > y || x < 0) {
            return 0LL;
        }
        if (x == y) {
            return 1LL;
        }
        if (y - x < x) {
            x = y - x;
        }

        std::vector<int> vis(x + 1);
        for (int i = 1; i <= x; i++) {
            vis[i] = i;
        }

        ll res = 1;
        for (int i = 1; i <= x; i++) {
            ll q = y - i + 1;
            for (int j = 1; j <= x; j++) {
                ll d = std::gcd(q, vis[j]);
                vis[j] /= d;
                q /= d;
            }
            res = res * q;
            //std::cout << res << "\n";
            for (int j = 1; j <= x; j++) {
                ll d = std::gcd(res, vis[j]);
                res /= d;
                vis[j] /= d;
            }
        }
        return res;
    };
    //std::cout << C(t, m + n) << "\n"; 
    //std::cout << C(t, n) << "\n";
    //std::cout << C(1, n) * C(t - 1, m) << "\n";
    //std::cout << C(2, n) * C(t- 2, m) << "\n";
    //std::cout <<  C(3, n) * C(t- 3, m) << "\n";
    //std::cout << C(30, 60) << "\n";

    std::cout << C(t, m + n) - C(t, n) -  C(1, n) * C(t - 1, m) - C(2, n) * C(t- 2, m) - C(3, n) * C(t- 3, m) - C(t, m)<< "\n";
}