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
 //   std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n;
    std::cin >> n;

    std::vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    ll sum = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        sum += a[i];
    }

    std::cout << sum << "\n";
}