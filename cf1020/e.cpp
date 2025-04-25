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
    while(t--) solve();
    return 0;
}
void solve(){
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    std::vector<int> c(n + 1);
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        c[a[i]] = i;
    }

    while(q--) {
        int l, r, k;
        std::cin >> l >> r >> k;

        if(c[k] < l || c[k] > r) {
            std::cout << -1 << " ";
            continue;
        }

        std::vector<int> cnt(2);
        auto cal = [&](int l, int r, int k) {
            int mid = (l + r) / 2;
            int min = k - 1;
            int max = n - k;
            while(mid != c[k]) {
                //std::cout << mid << "\n";
                if(c[k] > mid) {
                    if(a[mid] > k) {
                        cnt[0]++;
                    }
                    else {
                        min--;
                    }
                    l = mid + 1;
                }
                else {
                    if(a[mid] < k) {
                        cnt[1]++;
                    }
                    else {
                        max--;
                    }
                    r = mid - 1;
                }
                mid = (l + r) / 2;        
            }
            return cnt[0] <= min and cnt[1] <= max and min >= 0 and max >= 0;
        };
        if(cal(l, r, k)) {
            std::cout << 2 * std::max(cnt[0], cnt[1]) << " "; 
        }
        else {
            std::cout << -1 <<  " ";
        }
    }
    std::cout << "\n";
}
