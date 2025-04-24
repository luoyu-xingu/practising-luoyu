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

    if(std::count(s.begin(), s.end(), s[0]) == n) {
        std::cout << -1 << "\n";
        return;
    }

    std::vector<int> cnt(3, 0);
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') {
            a[0] = 0;
            cnt[0]++;
        }
        else if(s[i] == 'I') {
            a[i] = 1;
            cnt[1]++;
        }
        else {
            a[i] = 2;
            cnt[2]++;
        }
    }

    std::vector<int> ans;
    //std::cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << "\n";
    int min = *std::min_element(cnt.begin(), cnt.end());
    //std::cout <<  min << '\n';
    for(int x = 0; x < 3; x++) {
        if(cnt[x] == min) continue;
        int p = 1;
        while((a[p] == x) == (a[p - 1] == x)) {
            p++;
        }
        while(cnt[x] > min) {
            if(a[p] == x) {
                int y = a[p - 1];
                a.insert(a.begin() + p, 3 - x - y);
                ans.push_back(p);
                p++;
                a.insert(a.begin() + p, y);
                ans.push_back(p);
                p++;
            }
            else {
                int y = a[p];
                a.insert(a.begin() + p, 3 - x - y);
                ans.push_back(p);
                a.insert(a.begin() + p, y);
                ans.push_back(p);
            }
            cnt[x]--;
        }
    }

    std::cout << ans.size() << "\n";
    for(auto x : ans) {
        std::cout << x << "\n";
    }
}