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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    std::vector<int> b(m + 1);

    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    for(int i = 1; i <= m; i++) {
        std::cin >> b[i];
    }

    std::vector<int> pre(n + 1), suf(n + 2);

    int p = 1;
    for(int i = 1; i <= n; i++) {
        if(p > m) {
            pre[i] = pre[i - 1];
        }
        else {
            pre[i] = pre[i - 1];
            if(a[i] >= b[p]) {
                pre[i]++;
                p++;
            }
        }
    }

    p = m;

    for(int i = n; i >= 1; i--) {
        if(p < 1) {
            suf[i] = suf[i + 1];
        }
        else {
            suf[i] = suf[i + 1];
            if(a[i] >= b[p]) {
                suf[i]++;
                p--;
            }
        }
    }

    int ans = inf;

    for(int i = 1; i <= n + 1; i++) {
        if(pre[i - 1] + suf[i] == m) {
            ans = 0;
        }
        else if(pre[i - 1] + suf[i] == m - 1) {
            ans = std::min(ans, b[pre[i - 1] + 1]);
        }
    }
    if(ans == inf) {
        std::cout << -1 << "\n";
    }
    else {
        std::cout << ans << "\n";
    }
}

//贪心策略维护前缀配对数量和后缀配对数量。
//然后遍历每个i,如果前i - 1个配对数量和从i开始往后的配对数量等于m - 1,那么这个插入就是有效的， 插入最小的值为b[pre[i -  1] + 1];答案就是所有有效插入的最小值。
//如果不用插入就可以配对，那么答案就是0。
//注意循环需要到 n + 1，因为可以在最后插入。
