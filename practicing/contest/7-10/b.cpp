#include<bits/stdc++.h>

using ll = long long;

const int mod = 1e9 + 7;
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
    int r, c;

    std::cin >> r >> c;

    std::vector<std::string> a(r);
    for (int i = 0; i < r; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> cnt(c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == '1') {
                cnt[j].push_back(i);
            }
        }
    }

    std::vector<int> fa(2 * r);
    std::iota(fa.begin(), fa.end(), 0);

    auto find = [&](this auto &&self, int x) {
        if (x == fa[x]) {
            return x;
        }
        return fa[x] = self(fa[x]);
    };

    auto join = [&](int x, int y) {
        fa[find(x)] = find(y);
    };

    bool ok = true;
    for (int j = 0; j < c ; j++) {
        if (cnt[j].size() + cnt[c - j - 1].size() > 2) {
            ok = false;
        }
    }

    if (!ok) {
        std::cout << 0 << "\n";
    } else {
        for (int j = 0; 2 * j + 1 < c; j++) {
            if (cnt[j].size() + cnt[c - j - 1].size() == 2) {
                if (cnt[j].size() == 2 || cnt[c - j - 1].size() == 2) {
                    int x, y;
                    if (cnt[j].size() == 2) {
                        x = cnt[j][0];
                        y = cnt[j][1];
                    } else {
                        x = cnt[c - j - 1][0];
                        y = cnt[c - j - 1][1];
                    }

                    join(x, y + r);
                    join(y, x + r);
                } else {
                    int x = cnt[j][0];
                    int y = cnt[c - j - 1][0];
                    join(x, y);
                    join(x + r, y + r);
                }
            }
        }

        for (int i = 0; i < r; i++) {
            if (find(i) == find(i + r)) {
                ok = false;
            }
        }

        if (!ok) {
            std::cout << 0 << "\n";
        } else {
            int cnt = 0;
            for (int i = 0; i < 2 * r; i++) {
                if (i == find(i)) {
                    cnt++;
                }
            }

            assert(cnt % 2 == 0);

            ll res = 1;
            for (int i = 1; i <= cnt / 2; i++) {
                res *= 2;
                res %= mod;
            }

            std::cout << res << "\n";
        }
    }
}