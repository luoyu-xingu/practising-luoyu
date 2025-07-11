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

    int t = 1;
    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int l, r;
    std::cin >> l >> r;

    if (l & 1) {
        if (r & 1) {
            std::cout << "Alice\n";
        } else {
            if (l * 2 <= r) {
                std::cout << "Alice\n"; 
            } else {
                std::cout << "Bob\n";
            }
        }
    } else {
        // l 偶数
        if (r & 1) {
            std::cout << "Bob\n";
        } else {
            if (2 * (l + 1) <= r) {
                std::cout << "Bob\n";
            } else {
                std::cout << "Alice\n";   
            }
        }
    }
    
}