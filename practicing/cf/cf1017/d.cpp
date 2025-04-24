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
    std::string p, s;
    std::cin >> p >> s;
    int lp = 0, rp = 0, ls = 0, rs = 0;
    bool ok = true;
    while(lp < p.size()) {
        while( rp < p.size() and p[lp] == p[rp]) rp++;
        while( rs < s.size() and s[rs] == s[ls]) rs++;
        if(p[lp] == s[ls]) {
            if(rp - lp > rs - ls || 2 * (rp - lp) < (rs - ls)) {
                ok = false;
                break;
            }
            else {
                lp = rp;
                ls = rs; 
            } 
        }
        else {
            ok = false;
            break;
        } 
    }
    //std::cout << ls << '\n';
    if(ls < s.size()) {
        ok = false;
    }
    if(ok) {
        std::cout << "YES\n";
    }
    else {
        std::cout << "NO\n";
    }
}