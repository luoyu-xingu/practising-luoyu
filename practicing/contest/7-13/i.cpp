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

    std::vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        d[a[i]]++;
    }

    std::vector<int> p, q;
    
    for (int i = 1; i <= n; i++) {
        if (d[i] == 2) {
            if (p.size() < 2 * k) {
                p.push_back(i);
                p.push_back(i);
            }
        } else if (d[i] == 0){
            if (q.size() < 2 * k) {
                q.push_back(i);
                q.push_back(i);
            }
        }
    }

    assert(p.size() == q.size());

    for (int i = 1; i <= n and p.size() < 2 * k and q.size() < 2 * k; i++) {
        if (d[i] == 1) {
            p.push_back(i);
            q.push_back(i);
        }
    }

    for (int i = 1; i <= 2 * k; i++) {
        std::cout << p[i - 1] << " \n"[i == n];
    }

    for (int i = 1; i <= 2 * k; i++) {
        std::cout << q[i - 1] << " \n"[i == n];
    }
}