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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector b(m, std::vector(n, std::string())); 
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> b[i][j];
        }
    }
    std::vector<char> ch(n);
    int x = -1;
    for(int i = 0; i < m; i++) {
        int res = 0;
        for(int j = 0; j < n; j++) {
            if(b[i][j] == a[j]) {
                ch[j] = 1;
                res++;
            }
        }
        x = std::max(res, x);
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(!ch[i]) {
            ok = false;
            break;
        } 
    }
    if(ok) {
        std::cout << 3 * n - 2 * x << '\n';
    }
    else {
        std::cout << -1 << '\n';
    }
}