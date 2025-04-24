#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    int t = 1;
    std::cin >> t;
    getchar();
    while(t--) solve();
    return 0;
}
void solve(){
    std::string s;
    std::getline(std::cin, s);
    s = ' ' + s; 
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') std::cout << s[i + 1];
    }
    std::cout << '\n';
}
