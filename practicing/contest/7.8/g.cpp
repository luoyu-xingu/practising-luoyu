#include<bits/stdc++.h>

using ll = long long;
const int N = 1e6 + 7;
const int MAXV = 1e9;
const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;
std::vector<int> minp;
std::vector<int> pris;
void sieve(int n) {
    minp.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = i;
            pris.push_back(i);
        }
        for (auto x : pris) {
            if (1LL * x * i > n) {
                break;
            }
            minp[i * x] = x;
            if (minp[i] == x) {
                break;
            }
        }
    }
}

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    sieve(N);
    int t = 1;
    //std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::array<int, 2>>> e(n + 1);
    for (int i = 2; i <= n; i++) {
        e[i - 1].push_back({i, 1});
    }

    e[n - 1].back()[1]= pris.back() - (n - 2);

    auto sp = pris.back(), mst = pris.back();

    assert(sp == minp[sp] and mst == minp[mst]);
    std::cout << sp << " " << mst << "\n";

    m -= n - 1;
    int cnt = 0;
    for (int i = 1; i <= n and cnt < m; i++) {
        for (int j = i + 2; j <= n and cnt < m; j++) {
            cnt++;
            e[i].push_back({j, MAXV});
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (auto [x, y] : e[i]) {
            std::cout << i << " " << x << " " << y << "\n";
            sum++;
        }    
    }

    assert(sum == m + n - 1);

}