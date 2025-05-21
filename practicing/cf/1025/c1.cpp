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
    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n;
    std::cin >> n;

    int res;
    std::cout << "digit " << std::endl;
    std::cin >> res;

    std::cout << "digit " << std::endl;
    std::cin >> res;

    for (int i = 8; i >= 1; i /= 2) {
        std::cout << "add " << -i << std::endl;
        std::cin >> res;
    }

    std::cout << "add " << n - 1 << std::endl;
    std::cin >> res;

    std::cout << "! " << std::endl;
    std::cin >> res;
}