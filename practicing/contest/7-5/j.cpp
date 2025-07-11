#include<bits/stdc++.h>
using ll = long long;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int m, p;
    std::cin >> m >> p;

    std::vector<int> fa(m + 1);
    std::iota(fa.begin(), fa.end(), 0);

    // sum[r] - sum[l - 1];
    auto find = [&](auto &&self, int x) {
        if (fa[x] == x) {
            return x;
        }
        return fa[x] = self(self, fa[x]);
    };

    auto join = [&](int u, int v) {
        int lf = find(find, u);
        int rf = find(find, v);
        if (lf == rf) {
            return;
        }
        fa[lf] = rf;
    };

    while(p--) {
        int l, r;
        std::cin >> l >> r;
        l--;
        join(l, r);
    }

    bool ok = true;
    if (find(find, m) != find(find, 0)) {
        ok = false;
    }

    if (ok) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

}

