#include<bits/stdc++.h>

using ll = long long;

struct line {
    int x;
    int lo, hi;
    int flag;
};

struct Tr {
    int len1 = 0, len2;
    int l = 0 , r = 0;
    int cnt = 0;
} ;

int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<line> a(2 * n + 1);
    std::vector<int> Y{-1};
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {x1, y1, y2, 1};
        a[i + n] = {x2, y1, y2, -1};
        Y.push_back(y1);
        Y.push_back(y2);
    }

    //std::cout << a.size() << "\n";
    //assert(a.size() == 2 * n + 1);
    std::sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
        return x.x < y.x;
    });

    std::sort(Y.begin(), Y.end());
    Y.erase(std::unique(Y.begin(), Y.end()), Y.end());

    int s = Y.size() - 1;
    Y.push_back(Y.back());
    std::vector<Tr> tr(s * 4 + 7);
    auto build = [&](auto &&self, int p, int l, int r) {
        if (r < l) {
            return;
        }
        tr[p].l = l, tr[p].r = r;
        if (l == r) {
            return;
        }

        int mid = (l + r) / 2;
        self(self, 2 * p, l, mid);
        self(self, 2 * p + 1, mid + 1, r);
    };

    build(build, 1, 1, s - 1);

    auto up = [&](auto &&self, int p, int x, int y, int f) -> void {
        if (tr[p].l > y || tr[p].r < x) {
            return ;
        }
        if (tr[p].l >= x and tr[p].r <= y) {
            tr[p].cnt += f;
        } else {
            self(self, 2 * p, x, y, f);
            self(self, 2 * p + 1, x, y, f);
        }

        if (tr[p].cnt != 0) {
            if (tr[p].cnt % 2 == 1) {
                if (tr[p].l == tr[p].r) {
                    tr[p].len1 = Y[tr[p].r + 1] - Y[tr[p].l];
                    tr[p].len2 = 0;
                } else {
                    tr[p].len1 = Y[tr[p].r + 1] - Y[tr[p].l] - tr[2 * p].len1 - tr[2 * p + 1].len1;
                    tr[p].len2 = tr[2 * p].len1 + tr[2 * p + 1].len1; 
                }
            } else {
                if (tr[p].l == tr[p].r) {
                    tr[p].len2 = Y[tr[p].r + 1] - Y[tr[p].l];
                    tr[p].len1 = 0;
                } else {
                    tr[p].len2 = Y[tr[p].r + 1] - Y[tr[p].l] - tr[2 * p].len1 - tr[2 * p + 1].len1;
                    tr[p].len1 = tr[2 * p].len1 + tr[2 * p + 1].len1; 
                }
            }
        } else if (tr[p].l != tr[p].r) {
            tr[p].len1 = tr[2 * p].len1 + tr[2 * p + 1].len1;
            tr[p].len2 = tr[2 * p].len2 + tr[2 * p + 1].len2;
        } else {
            tr[p].len1 = tr[p].len2 = 0;
        }
    };

    //assert(false);
    ll ans = 0;
    for (int i = 1; i < 2 * n; i++) {
        int lo = std::lower_bound(Y.begin() + 1, Y.end(), a[i].lo) - Y.begin();
        int hi = std::lower_bound(Y.begin() + 1, Y.end(), a[i].hi) - Y.begin();
        
        up(up, 1, lo, hi - 1, a[i].flag);

        ans += 1LL * tr[1].len1 * (a[i + 1].x - a[i].x);
    }

    std::cout << ans << "\n";
    return 0;
}