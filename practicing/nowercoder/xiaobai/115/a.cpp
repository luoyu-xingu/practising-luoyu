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
//    std::cin >> t;
    while(t--) solve();
    return 0;
}
void solve(){
    int a, b, c;
    std::cin >> a >> b >> c;
    if(b == 0) {
        if(a != c  and a != 0 and c != 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    } else{
        if(a == c and a == 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}