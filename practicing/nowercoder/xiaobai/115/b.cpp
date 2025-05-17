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
//    std::cin >> t;
    while(t--) solve();
    return 0;
}
void solve(){
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        b[a[i]]++;
    }

    std::ranges::sort(a);

    int ans = std::min(b[a[0]], m);
    for (int i = 0; i < n; i += b[a[i]]) {
        if (n - i < m) {
            break;
        }
        ans = std::max(std::min(m, b[a[i]]), ans);
    } 

    std::cout << ans << "\n";
}