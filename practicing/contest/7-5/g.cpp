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
    ll n;
    std::cin >> n;

    ll ans = 0;
    for (ll l = 1; l <= n; l++) {
        ll v  = n / l;
        ll r = n / v;
        ans += v * (r - l + 1);
        l = r;
    }
    std::cout << ans << "\n";
}

