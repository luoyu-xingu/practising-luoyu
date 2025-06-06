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
    int n;
    std::string s;
    std::cin >> n >> s;
    int cnt = 0;

    for(auto c : s) {
        if(c == '1') {
            cnt++;
        }
    }

    ll ans = 0;
    for(auto c : s) {
        if(c == '1') {
            ans += cnt - 1;
        }
        else {
            ans += cnt + 1;
        }
    }
    
    std::cout << ans << "\n";
}

//统计1的个数，接下来换的时候，如果是1 那么1的个数少1，否则会多一个1
