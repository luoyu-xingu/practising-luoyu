#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAXV = 1e18;
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
    int q;
    std::cin >> q;

    std::vector<int> fal(q + 2, -1), far(q + 2, -1);
    std::vector<ll> len(q + 2);
    std::vector fa(q + 2, std::vector<int>(20, -1));
    std::vector L(q + 2, std::vector<ll>(20)), R(q + 2, std::vector<ll>(20));

    len[0] = 1;
    len[1] = 1;
    for (int i = 2; i <= q + 1; i++) {
        int l, r;
        ll x;
        std::cin >> l >> r >> x;
        fal[i] = l;
        far[i] = r;
        len[i] = std::min(MAXV, len[l] + len[r]);

        if (len[l] >= len[i] - len[l]) {
            fa[i][0] = l;
            R[i][0] = len[i] - len[l];
        } else {
            fa[i][0] = r;
            L[i][0] = len[l];
        }

        for (int j = 1; j < 20; j++) {
            if (fa[i][j - 1] == -1 || fa[fa[i][j - 1]][j - 1] == -1) {
                continue;
            }
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            L[i][j] = L[i][j - 1] + L[fa[i][j - 1]][j - 1];
            R[i][j] = R[i][j - 1] + R[fa[i][j - 1]][j - 1];
        }

        auto p = i;
        while(p >= 2) {
            for (int j = 19; j >= 0; j--) {
                assert(p != -1);
                if (fa[p][j] == -1) {
                    continue;
                }
                if (x > L[p][j] and x <= len[p] - R[p][j]) {
                    x -= L[p][j];
                    p = fa[p][j];
                }
            }

            if (p >= 2) {
                if (x > len[fal[p]]) {
                    x -= len[fal[p]];
                    p = far[p];
                } else {
                    p = fal[p];
                }
            }
        }
        assert(p == 0 || p == 1);
        std::cout << p << "\n";
    }

}