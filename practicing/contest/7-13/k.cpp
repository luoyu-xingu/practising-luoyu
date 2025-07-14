#include<bits/stdc++.h>

using ll = long long;

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

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    
    int n = a.size(), m = b.size();

    int ans = -1;

    for (int i = 0; i < m; i++) {
        int p = i;
        for (auto c : a) {
            if (p < m and c == b[p]) {
                p++;
            }
        }
        ans = std::max(ans, p - i);
    }

    std::cout << n + m -ans << "\n";


}