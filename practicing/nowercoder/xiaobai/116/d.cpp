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

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int pos = -1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[0]) {
            pos = i; 
            break;
        }
    }

    if (pos == -1) {
        std::cout << 1 << "\n";
    }
    for (int i = pos; i < n; i++) {
        if (s[i] != s[pos]) {
            std::cout << 2 << "\n";
            return;
        }
    }

    std::cout << 1 + std::min(n - pos, 3) << "\n";
}