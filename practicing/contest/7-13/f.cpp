
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
    int n, k, pa, pb;
    std::cin >> n >> k >> pa >> pb;

    pa--, pb--;

    std::vector<int> p(n);

    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
    }

    std::vector<int> a(n);
    for (int i =  0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> vis(n);

    ll ans1 = 0, ans2 = 0;
    int cnt = 0;
    ll sum = 0;
    while(!vis[pa] && cnt <= k) {
        vis[pa] = 1;
        ans1 = std::max(ans1, sum + 1LL * (k - cnt) * a[pa]);
        sum += a[pa];
        cnt++;
        pa = p[pa];
    }

    vis = std::vector<int>(n, 0);
    cnt = 0;
    sum = 0;
    while(!vis[pb] && cnt <= k) {
        vis[pb] = 1;
        ans2 = std::max(ans2, sum + 1LL * (k - cnt) * a[pb]);
        sum += a[pb];
        cnt++;
        pb = p[pb];        
    }

    //std::cout << ans1 << " " << ans2 << "\n";
    if (ans1 > ans2) {
        std::cout << "Bodya\n";
    } else if (ans1 < ans2) {
        std::cout << "Sasha\n";
    } else {
        std::cout << "Draw\n";
    }
}