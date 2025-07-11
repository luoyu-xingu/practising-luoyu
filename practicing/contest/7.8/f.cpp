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
    int n, k;
    std::cin >> n >> k;

    std::string s, t;
    std::cin >> s >> t;
    std::vector<std::array<int, 26>> cnt(2);
    for (int i = 0; i < n; i++) {
        if (i + k < n || i >= k) {
            cnt[0][s[i] - 'a']++;
            cnt[1][t[i] - 'a']++;
        } else {
            if (s[i] != t[i]) {
                std::cout << "NO\n";
                return;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[0][i] != cnt[1][i]) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}