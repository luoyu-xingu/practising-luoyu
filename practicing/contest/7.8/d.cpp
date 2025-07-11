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
    int n;
    std::cin >> n;

    std::vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)  {
        std::cin >> a[i];
    }

    int q = 30;
    std::vector st(n + 1, std::vector<ll>(q + 1, Inf));

    std::vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            b[i] = i + 1;
        } else if (i == n) {
            b[i] = i - 1;
        } else if (a[i + 1] - a[i] < a[i] - a[i - 1]) {
            b[i] = i + 1;
        } else {
            b[i] = i - 1;
        }
    }

    for (int i = 1; i < n; i++) {
        if (b[i] == i + 1) {
            st[i][0] = std::min<ll>(1, a[i + 1] - a[i]);
        } else {
            st[i][0] = a[i + 1] - a[i];
        }
    }
    for (int j = 1; j <= q; j++) {
        for (int i = 1; i + (1 << j) <= n; i++) {
            st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
        }
    }

    std::vector nst(n + 1, std::vector<ll>(q + 1, Inf));

    for (int i = n; i > 1; i--) {
        if (b[i] == i - 1) {
            nst[i][0] = std::min<ll>(1, a[i] - a[i - 1]);
        } else {
            nst[i][0] = a[i] - a[i - 1];
        }
    }
    for (int j = 1; j <= q; j++) {
        for (int i = n; i - (1 << j) >= 1; i--) {
            nst[i][j] = nst[i][j - 1] + nst[i - (1 << (j - 1))][j - 1];
        }
    }


    int m;
    std::cin >> m;
    while(m--) {
        int x, y;
        std::cin >> x >> y;

        if (x <= y) {
            ll k = y - x;
            ll ans = 0;
            int nw = x;
            for (int i = 29; i>= 0; i--) {
                if ((k >> i) & 1) {
                    int j = 1 << i;
                    ans += st[nw][i];
                    nw += j;
                    k -= j;
                } 
            }
            std::cout << ans << "\n";
        } else {
            ll k = x - y;
            ll ans = 0;
            int nw = x;
            for (int i = 29; i>= 0; i--) {
                if ((k >> i) & 1) {
                    int j = 1 << i;
                    ans += nst[nw][i];
                    nw -= j;
                    k -= j;
                } 
            }
            std::cout << ans << "\n";
        }

    }
}
