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
    int a, b, c;
    std::cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum % 3) {
        std::cout << "NO\n";
    } else {
        int mid = sum / 3;
        if (a <= mid and b <= mid) {
            if(mid - a + mid - b == c - mid) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        } else {
            std::cout << "NO\n";
        }
    }
}