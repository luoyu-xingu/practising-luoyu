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
    std::string s;
    std::cin >> s;
    
    int n = s.size();
    int ans = 0;
    for (int d = 2; d <= n; d += 2) {
        int l = 0, r = l + d - 1;
        //std::cout << d << "    ";
        while (r < n) {
            while (l + d / 2 <= r) {
                if (s[l] == s[l + d / 2] || s[l] == '?' || s[l + d / 2] == '?') {
                    l++;
                } else {
                    break;
                }
            }
            //std::cout << l << " ";
            if (l + d / 2 > r) {
                ans = std::max(ans, d);
                break;
            } else {
                l++;
                r = l + d - 1;
            }
        }
        //std::cout << "\n";
    }

    std::cout << ans << "\n";
}