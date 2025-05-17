#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

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

void solve(){
    int n, q;
    std::cin >> n >> q;
    
    std::vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    while(q--) {
        int l, r;
        std::cin >> l >> r;
        if (r - l + 1 >= 64) {
            std::cout << 0 << "\n";
            continue;
        }
        ll ans = 0;
        ans = a[l];
        for (int i = l + 1; i <= r; i++) {
            ans = 2LL * (ans & a[i]);
        }
        std::cout << ans << "\n";
    }
}