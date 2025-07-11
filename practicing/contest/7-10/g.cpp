#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    //std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
        a[i] -= i;
        b[i] -= i;
    }

    std::vector<int> c(n);
    std::iota(c.begin(), c.end(), 0);

    std::ranges::sort(c, 
        [&](auto x, auto y) {
           if (a[x] != a[y]) return a[x] < a[y];
           return b[x] > b[y];
        });

    std::stack<int> stk;

    for (int i = 0; i < n; i++) {
        if(!stk.empty()) {
            auto x = stk.top();
            if (x >= b[c[i]]) {
                stk.pop();
                while(!stk.empty() and stk.top() >= b[c[i]]) {
                    stk.pop();
                }
                stk.push(x);
            } else {
                stk.push(b[c[i]]);
            }
        } else {
            stk.push(b[c[i]]);
        }
    }

    std::cout << stk.size() << "\n";
}