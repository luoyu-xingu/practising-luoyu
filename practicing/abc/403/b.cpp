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
    std::string T, U;
    std::cin >> T >> U;

    auto check = [&](int p) {
        int x = p, y = 0;
        if (x + U.size() - 1>= T.size()) {
            return false;
        }

        for (int i = p; i <= p + U.size() - 1; i++) {
            if(T[i] != U[i - p] and T[i] != '?') {
                return false;
            }
        }
        return true;
    };

    for (int i = 0; i < T.size(); i++) {
        if (check(i)) {
            std::cout << "Yes\n";
            return;
        }
    }

    std::cout << "No\n";
}