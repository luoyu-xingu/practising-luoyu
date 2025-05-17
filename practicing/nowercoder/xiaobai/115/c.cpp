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
    //std::cin >> t;
    while(t--) solve();
    return 0;
}
void solve(){
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int q, m;
    std::cin >> q >> m;
    
    std::vector<int> cnt(101);
    //for (int i = n - 1; i >= 1; i--) {
    //    for (int j = a[i]; j <= 100; j++) {
    //        cnt[j]++;
    //    }
    //}

    std::vector<int> pass(n);

    int ans = inf;
    if (m < a[0]) {
        pass[0]++;
    }

    for (int i = 1; i < n; i++) {
        if(m < a[i]) {
            pass[i] = pass[i - 1] + 1;
        } else {
            pass[i] = pass[i - 1];
        }
    }
    
    for (int i = n - 1; i >= 1; i--) {
        int res = 0;
        for(int j = a[i] + 1; j <= 100; j++) {
            res += cnt[j];
        }

        ans = std::min(ans, pass[i] + res);
        cnt[a[i]]++;
    }
    
    std::cout << ans << "\n";
}
