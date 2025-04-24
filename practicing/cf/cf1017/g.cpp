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
    int m;
    std::cin >> m;
    std::deque<int> q,rq;
    ll ans = 0;
    ll rans = 0;
    ll sum = 0;

    while(m--) {
        int s;
        std::cin >> s;
        if(s == 1) {
            int t = q.back();
            q.pop_back();
            q.push_front(t);
            ans += sum - 1LL * q.size() * t;

            t = rq.front();
            rq.pop_front();
            rq.push_back(t);
            rans += -sum + 1LL * rq.size() * t;
        }
        else if(s == 2) {
            std::swap(ans, rans);
            std::swap(q, rq);
        }
        else {
            int k;
            std::cin >> k;
            sum += k;
            q.push_back(k);
            rq.push_front(k);
            ans += 1LL * q.size() * k;
            rans += sum;
        }
        std::cout << ans << "\n";
    }
    
}