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
    std::string s;
    std::cin >> s;

    int n = s.size();

    ll cnt[2];
    cnt[0] = cnt[1] = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            cnt[1] += cnt[0];
        } else if (s[i] == 'Q'){
            cnt[0]++;
            ans += cnt[1];
        }
    }

    std::cout << ans << "\n";
}