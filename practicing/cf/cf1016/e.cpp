#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    int t = 1;
    std::cin >> t;
    while(t--) solve();
    return 0;
}
void solve(){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int l = 0,r = n;
    int ans = 0;
    auto check = [&](int p) {
        int q = p;
        std::vector<bool> e(p);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] < p and !e[a[i]]) {
                e[a[i]] = 1;
                q--;
            }
            if(q == 0) {
                e = std::vector<bool>(p);
                q = p;
                cnt++;
            }
        }
        return cnt >= k;
    };

    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    std::cout << ans << '\n';
}