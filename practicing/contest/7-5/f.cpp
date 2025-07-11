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
    int n, q;
    std::cin >> n >> q;

    std::vector e(n + 1, std::vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    std::vector<int> dfn(n + 1), rdfn(n + 1), top(n + 1), hson(n + 1);
    std::vector<int> sze(n + 1), fa(n + 1);
    auto dfs1 = [&](auto &&self, int u, int f) -> void {
        sze[u] = 1;
        fa[u] = f;
        for (auto v : e[u]) {
            if (v == fa[u]) {
                continue;
            }
            self(self, v, u);
            sze[u] += sze[v];
            if (sze[hson[u]] < sze[v]) {
                hson[u] = v;
            }
        }
    };
    dfs1(dfs1, 1, 1);

    int cur = 0;
    auto dfs2 = [&](auto &&self, int u, int f) -> void {
        top[u] = f;
        dfn[u] = ++cur;
        rdfn[cur] = u;

        if (hson[u] == 0) {
            return;
        }
        self(self, hson[u], f);

        for (auto v : e[u]) {
            if (v == hson[u] || v == fa[u]) {
                continue;
            }
            self(self, v, v);
        } 
    };
    dfs2(dfs2, 1, 1);


    std::vector<ll> a(n + 1);

    std::vector<ll> tr(4 * n + 7), lazy(4 * n + 7);

    auto push = [&](int p, int l, int r) {
        int lson = 2 * p ;
        int rson = 2 * p + 1;
        int mid = (l + r) / 2;
        if (lazy[p] == 0) {
            return;
        }
        tr[lson] += (mid - l + 1) * lazy[p];
        tr[rson] += (r - mid) * lazy[p];
        lazy[lson] += lazy[p];
        lazy[rson] += lazy[p];
        lazy[p] = 0;
    };

    auto Rapply = [&](auto &&self, int p, int l, int r, int x, int y, int z) {
        if (l > r) {
            return;
        }
        if (x <= l and y >= r) {
            tr[p] += 1LL * (r - l + 1) * z;
            lazy[p] += z;
            return;
        }

        push(p, l, r);
        int mid = (l + r) / 2; 
        if (x > mid) {
            self(self, 2 * p + 1, mid + 1, r, x, y, z);
        } else if (y <= mid) {
            self(self, 2 * p, l, mid, x, y, z);
        } else {
            self(self, 2 * p + 1, mid + 1, r, x, y, z);
            self(self, 2 * p, l, mid, x, y, z);
        }
    };

    auto Rquery = [&](auto &&self, int p, int l, int r, int x, int y) {
        if (l > r) {
            return 0LL;
        }
        if (x <= l and y >= r) {
            return tr[p];
        }
        push(p, l, r);
        int mid = (l + r) / 2; 
        if (x > mid) {
            return self(self, 2 * p + 1, mid + 1, r, x, y);
        } else if (y <= mid) {
            return self(self, 2 * p, l, mid, x, y);
        } else {
            return self(self, 2 * p + 1, mid + 1, r, x, y) + self(self, 2 * p, l, mid, x, y);
        }
    };


    while(q--) {
        int j, x;
        std::cin >> j >> x;
        //std::cout << j << " " << x << " ";
        //std::cout << Rquery(Rquery, 1, 1, n, dfn[j], dfn[j] + sze[j] - 1) << "\n";
        Rapply(Rapply, 1, 1, n, dfn[j], dfn[j] + sze[j] - 1, x);
    }

   /*  std::cout << tr[1] << "\n";
    std::cout << lazy[1] << "\n"; */
    for (int i = 1; i <= n; i++) {
        a[i] = Rquery(Rquery, 1, 1, n, dfn[i], dfn[i]);
    }

    for (int i = 1; i <= n; i++) {
        std::cout << a[i] << " \n"[i == n];
    }
}

