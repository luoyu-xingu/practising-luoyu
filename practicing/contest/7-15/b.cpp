#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 7;
std::vector<int> minp, prime;
void sieve(int n) {
    minp.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            prime.push_back(i);
            minp[i] = i;
        } 
        for (auto x : prime) {
            if (1LL * x * i > n) {
                break;
            }
            minp[i * x] = x;
            if (x == minp[i]) {
                break;
            }
        }
    }
}

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    sieve(N);
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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> c;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        while(a[i] != 1) {
            a[i] /= minp[a[i]];
            cnt++;
        }
        c.push_back(cnt);
    }

    ll ans = 0;
    for (int i = 0; i < c.size(); i++) {
        ans ^= c[i];
    }

    if (ans == 0) {
        std::cout << "Bruno\n";
    } else {
        std::cout << "Anna\n";
    }
}