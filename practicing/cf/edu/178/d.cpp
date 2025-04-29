#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7 + 7;
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
            if (i % x == 0) {
                break;
            }
        }
    }
}

std::vector<ll> pre;
void init() {
    pre.assign(prime.size() + 1, 0);
    for(int i = 0; i < prime.size(); i++) {
        pre[i + 1] = pre[i] + prime[i];
    }
}

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(15);
    sieve(N);
    init();
    int t = 1;
    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n;
    std::cin >> n;
    
    std::vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::ranges::sort(a, std::greater<int>());

    int ans = n - 1;
    std::vector<ll> sum(n + 1);

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i - 1];
    }

    //std::cout << sum[n] << "\n"; 
    for (int i = n; i >= 1; i--) {
        if (pre[i] <= sum[i]) {
            ans = n - i;
            break;
        }
    }

    std::cout << ans << "\n";
}