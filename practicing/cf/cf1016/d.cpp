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
    int n, q;
    std::cin >> n >> q;
    ll p = 1;
    for(int i = 1; i <= 2 * n; i++) {
        p *= 2LL;
    } 
    ll o = 1;
    for(int i =1; i <= n; i++) {
        o *= 2LL;
    }
    while(q--) {
        std::string s;
        std::cin >> s;
        if(s == "->") {
            int x, y;
            std::cin >> x >> y;
            ll ans = 0;
            auto find = [&](this auto &&self, int x, int y, ll a, ll b, ll c, ll d, ll res, ll m) {
                /* std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
                std::cout << res << '\n'; */
                if(a >= b || c >= d) {
                    if(a == b and c == d and x == a and y == c) {
                        //std::cout << a << ' ' << c << '\n';
                        ans = res + 1;
                        return;
                    }
                    return;
                }

                int midx = (a + b) / 2;
                int midy = (c + d) / 2;
                if(x <= midx and y <= midy) {
                    self(x, y, a, midx, c, midy, res + 0, m / 4);
                }
                else if(x <= midx and y > midy) {
                    self(x, y, a, midx, midy + 1,d, res + m / 4 * 3, m / 4);
                }
                else if(x > midx and y <= midy) {
                    self(x, y, midx + 1, b, c, midy, res + m / 4 * 2, m / 4);
                }
                else {
                    self(x, y, midx + 1, b, midy + 1, d, res + m / 4, m / 4);
                }
            };
            find(x, y, 1, o, 1, o, 0, p);
            std::cout << ans << '\n';
        }
        else {
            ll d;
            std::cin >> d;
            std::pair<int, int> ans;
            auto find = [&](this auto &&self, ll x, ll a, ll b, ll c, ll d,ll res, ll m) {
               // std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << '\n'; 
                //std::cout << m << '\n';
                if(a >= b || c >= d) {
                    if(a == b and c == d and x == res + 1) {
                        //std::cout << a << ' ' << c << '\n';
                        ans.first = a;
                        ans.second = c;
                        return;
                    }
                    return;
                }
                int midx = (a + b) / 2;
                int midy = (c + d) / 2;
                if(x <= res + m / 4) {
                    self(x, a, midx, c, midy, res + 0, m / 4);
                }
                else if(x <= res + m / 4 * 2) {
                    self(x, midx + 1, b, midy + 1, d, res + m / 4, m / 4);
                }
                else if(x <= res + m / 4 * 3) {
                    self(x, midx + 1, b, c, midy, res + m / 4 * 2, m / 4);
                }
                else {
                    self(x, a, midx, midy + 1, d, res + m / 4 * 3, m / 4);
                }
            };
            find(d, 1, o, 1, o, 0, p);
            std::cout << ans.first << ' ' << ans.second << '\n';
        }
    }

}