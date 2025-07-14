#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

const int x=10;

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
    
    auto ans = [&](int a) {
        std::cout << "!" << " " << a << std::endl;
    };

    auto ask = [&](int a, int b) {
        std::cout << "?" << " " << a << " " << b << std::endl;

        assert(a <= b);
        int s;
        std::cin >> s;

        if (s == a * b) {
            return 1;
        } else if (s == a * (b + 1)) {
            return 2;
        } else {
            return 0;
        }

        assert(false);
    };

    int l = 2, r = 999;
    while(l < r) {
        int mid1 = 2 * l / 3 + r / 3;
        int mid2 = l / 3 + 2 * r / 3;

        auto p = ask(mid1, mid2);
        if (p == 1) {
            l = mid2 + 1;
        } else if (p == 2) {
            l = mid1 + 1;
            r = mid2;
        } else {
            r = mid1;
        }
    }

    ans(l);
}




