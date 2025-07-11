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

    std::cout << std::fixed << std::setprecision(15);

    int t = 1;
    //std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){ 
    ll n;
    std::cin >> n;

    ll ans = 0;
    auto cal = [&](int p) {
        return (int) pow(n, 1.0 / p);
    };
    for (int i = 2; i <= 20; i++) {
        ans += cal(i);
    }

    std::cout << ans << "\n";
}