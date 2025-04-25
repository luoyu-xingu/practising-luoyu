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
    while(t--) solve();
    return 0;
}
void solve(){
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for(int i = 0; i < x; i++) {
        a[i] = i;
    }

    int p = 1;
    for(int i = x; i < n; i++) {
        a[i] = n - p++;
    }

    for(auto v : a) {
        std::cout << v << " \n"[v == a.back()];
    }

}