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
    std::vector<int> a(4);
    int x;
    for (int i = 1; i <= 3;i++) {
        std::cin >> a[i];
    }
    std::cin >> x;
    if (*std::max_element(a.begin(), a.end()) == a[x]) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}