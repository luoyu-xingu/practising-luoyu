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
    std::string  x;
    std::cin >> x;

    std::string ans = x;
    ll r = 0;
    for (int i = 0; i < x.size(); i++) {
        r += x[i] - '0';
    }

    auto cal = [&](int o) -> std::pair<ll, std::string> {
            if (x[o] == '0') {
                return {-Inf, ""};
            } 

            std::string res;
            ll q = 0;
            if (o != 0 || x[o] != '1') {
                res.push_back(x[o] - 1);
                q += x[o] - 1 - '0';
            }
            q += 9LL * (x.size() - o - 1);

            for (int i = o + 1; i < x.size(); i++) {
                res.push_back('9');
            }
            return {q, res};
    };


    std::string tmp;
    ll res = 0;
    for (int i = 0; i < x.size(); i++) {
        auto p = cal(i);
        if (res + p.first > r) {
            r = res + p.first;
            ans = tmp + p.second;
        } else if (res + p.first == r) {
            auto l = tmp + p.second;
            if (ans.size() < l.size()) {
                ans = l;
            } else if (ans.size() == l.size()){
                ans = std::max(ans, l);
            }
        }
        tmp += x[i];
        res += x[i] - '0';
    }
    std::cout << ans << "\n";
}