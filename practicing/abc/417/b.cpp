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
    int n, m;
    std::cin >> n >> m;

    std::multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        s.insert(x);
    }


    while (m--) {
        int y;
        std::cin >> y;
        auto x = s.find(y);
        if (x == s.end()) {
            continue;
        } else {
            s.erase(x);
        }
    }

    for (auto x : s) {
        std::cout << x << " ";
    }

    std::cout << "\n";
}