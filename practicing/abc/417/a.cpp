#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
//    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::string s;
    std::cin >> s;

    std::cout << s.substr(a, n - a - b) << "\n";
}