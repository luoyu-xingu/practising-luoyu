// function f(k, a, l, r):   
// ans := 0   
// for i from l to r (inclusive):     
//  while k is divisible by a[i]:         
//  k := k/a[i]      
//  ans := ans + k   
//  return ans

#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

std::vector<std::vector<int>> pos(1e5 + 7);

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
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    int max = -1;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        max = std::max(max, a[i]);
    }

    for(int i = 1; i <= n; i++) {
        pos[a[i]].push_back(i);
    }

    while(q--) {
        int k, l, r;
        std::cin >> k >> l >> r;
        //std::cout << k << '\n';
        //return;
        auto f = [&](int k, int l, int r) {
            std::vector<std::pair<int, int>> facts;
            //std::cout << k << '\n';
            for(int i = 1; i * i <= k; i++) {
                if(i > max) break;
                if(k % i == 0) {
                    if(pos[i].size() > 0 and std::lower_bound(pos[i].begin(), pos[i].end(), l) != pos[i].end() and *std::lower_bound(pos[i].begin(), pos[i].end(), l) <= r) {
                        facts.emplace_back(*std::lower_bound(pos[i].begin(), pos[i].end(), l), i);
                    }

                        if(i * i != k) {
                            int m = k / i;
                            if(m > max) continue;
                            if(pos[m].size() > 0 and std::lower_bound(pos[m].begin(), pos[m].end(), l) != pos[m].end() and *std::lower_bound(pos[m].begin(), pos[m].end(), l) <= r) {
                                facts.emplace_back(*std::lower_bound(pos[m].begin(), pos[m].end(), l), m);
                            }
                        }
                }
            }

            std::sort(facts.begin(), facts.end());

            ll ans = 0;

            for(const auto [p, v] : facts) {
                //std::cout << v << " ";
                ans += 1LL * (p - l) * k;
                while(k % v == 0) k /= v;
                l = p;
                //std::cout << "\n";
            }
            ans += 1LL * (r - l + 1) * k;

            return ans;
        };
        std::cout << f(k, l, r) << "\n";
    }

    for(int i = 1; i <= n; i++) {
        pos[a[i]].clear();
    }
}