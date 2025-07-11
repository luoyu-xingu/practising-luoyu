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

    bool ok = true;
    int cnt[2] = {0, 0};
    for (auto c : s) {
        if (c == '(' || c == ')') {
            cnt[1] = 0;
            cnt[0]++;
            if (cnt[0] > 2) {
                ok = false;
            }
        } else {
            cnt[0] = 0;
            cnt[1]++;
            if (cnt[1] > 2) {
                ok = false;
            }
        }
    }

    if (ok) {
        cnt[0] = cnt[1] = 0;
        int ans[2] = {0, 0};
        for (auto c : s) {
            if (c == '(' || c == ')') {
                cnt[1] = 0;
                cnt[0]++;
                if (cnt[0] == 2) {
                    ans[0]++;
                }
            } else {
                cnt[0] = 0;
                cnt[1]++;
                if (cnt[1] == 2) {
                    ans[1]++;
                }
            }
        }

        ok &= (ans[1] + ans[0] <= 2);
    }

    if (ok) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}