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
    int n;
    std::cin >> n;

    auto ask = [&](int x, int y) {
        std::cout << "?" << " " << x << " " << y << std::endl;
        int z;
        std::cin >> z;
        return z;
    };

    auto ans = [&](int a) {
        std::cout << "!" << " " << a << std::endl;
    };

    int x = -1, y = -1;
    for (int i = 1; i + 1 <= n; i += 2) {
        if (ask(i, i + 1)) {
            x = i, y = i + 1;
            break;
        }
    }

    if (x == -1 and y == -1) {
        if (n & 1) {
            if (ask(n - 1, n)) {
                x = n - 1, y = n;
            }
        }
    }

    if (x == -1 and y == -1) {
        ans(1);    
    } else {
        int a = -1, b = -1;
        for (int i = 1; i <= n; i++) {
            if (i != x and i != y and a == -1) {
                a = i;
            } else if (i != x and i != y and a != -1) {
                b = i;
                break;
            }
        }
        assert(a != -1 and b != -1);
        int p = ask(a, x);
        int q = ask(a, y);
        assert(!p || !q);
        if (!p and !q) {
            ans(1);
        } else if (p and !q) {
            int z = ask(b, x);
            if (z) {
                ans(2);
            } else {
                ans(1);
            }
        } else {
            int z = ask(b, y);
            if (z) {
                ans(2);
            } else {
                ans(1);
            }
        }   
    }
}