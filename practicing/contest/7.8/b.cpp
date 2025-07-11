#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
//    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    ll a, b;
    std::cin >> a >> b;

    std::vector<int> ans;
    ans.push_back(b);

    bool ok = true;
    while(b > a) {
        if (b % 10 == 1) {
            ans.push_back(((b - 1) / 10));
            b -= 1;
            b /= 10;
        } else if (b % 2 == 0) {
            b /= 2;
            ans.push_back(b);
        } else {
            ok = false;
            break;
        }
    } 

    if (!ok || ans.back() != a) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        std::cout << ans.size() << "\n";
        for (int i = ans.size() - 1; i >= 0; i--) {
            std::cout << ans[i] << " \n"[i == 0];
        }
    }
}