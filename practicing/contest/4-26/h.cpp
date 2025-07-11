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
    while(t--) solve();
    return 0;
}
void solve(){
    ll n;
    std::cin >> n;
    if (n % 3 == 0) {
        std::cout << "1 " << n / 3 << "\n";
    } else {
        std::cout << "0 " << n / 3 + n % 3 << "\n";
    }
}
