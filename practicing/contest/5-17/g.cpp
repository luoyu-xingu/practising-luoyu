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
    int n;
    std::cin >> n;
    
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> sufmax(n + 2, -1), sufmin(n + 2, inf);
    for (int i = n; i >= 1; i--) {
        sufmax[i] = std::max(sufmax[i + 1], a[i]);
        sufmin[i] = std::min(sufmin[i + 1], a[i]);
    }

    std::vector<int> premax(n + 1, -1), premin(n + 1, 0x3f3f3f3f);
    premax[1] = a[1];
    premin[1] = a[1];
    
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (premax[i - 1] >= a[i] and sufmin[i + 1] <= a[i]) {
            cnt++;
            premax[i] = premax[i - 1];
            premin[i] = premin[i - 1];
        } else if (premin[i - 1] <= a[i] and sufmax[i + 1] >= a[i]) {
            cnt++;
            premax[i] = premax[i - 1];
            premin[i] = premin[i - 1];
        } else {
            premax[i] = std::max(premax[i - 1], a[i]);
            premin[i] = std::min(premin[i - 1], a[i]);
        }
    }

    std::cout << n - cnt << "\n";

}