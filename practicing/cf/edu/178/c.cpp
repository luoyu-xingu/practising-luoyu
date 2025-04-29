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
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> cnt(2);
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'A') {
            cnt[0].push_back(i + 1);
        } else {
            cnt[1].push_back(i + 1);
        }
    }
    if (n == 2) {
        if (s.back() == 'B') {
            std::cout << "Alice\n";
        } else {
            std::cout << "Bob\n";
        }
    } else {
        if (s.back() == 'B' and cnt[1].size() != 1) {
            std::cout << "Bob\n";
        } else if(s.back() == 'B' and cnt[1].size() == 1) {
            std::cout << "Alice\n";
        } else {
            // s.back() == 'A';
            if (s[0] == 'A') {
                std::cout << "Alice\n";
            } else{
                if (cnt[0].size() > 1 and cnt[0][cnt[0].size() - 2] > cnt[1].back()) {
                    std::cout << "Alice\n";
                } else {
                    std::cout << "Bob\n";
                }
            }
        }
    }
}