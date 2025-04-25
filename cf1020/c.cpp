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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    bool ok = false;
    int res = -1;

    auto check = [&]() {
        for(int i = 0; i < n; i++) {
            if(b[i] != -1) {
                res = a[i] + b[i];
                return;
            }
        }
        return;
    };

    check();

    if(res != -1) {
        for(int i = 0; i < n; i++) {
            if(b[i] != -1) {
                if(a[i] + b[i] != res) {
                    std::cout << 0 << "\n";
                    return;
                }
            }
            else {
                if(res - a[i] > k || res - a[i] < 0) {
                    std::cout << 0 << "\n";
                    return;
                }
            }
        }
        std::cout << 1 << "\n";
    }

    else {
        int max = *std::max_element(a.begin(), a.end());
        int min = *std::min_element(a.begin(), a.end());

        int ans = k - (max - min) + 1;

        if(max - min > k) {
            std::cout << 0 << "\n";
        }
        else {
            std::cout << ans << "\n";
        }
    }
}

//其实条件很苛刻。
//如果b里面存在不是-1的，那么答案至多一个。任意选一个b[i] != -1, 然后判断其他的是否可行
//是否可行有两方面：1. 其余b[i] != -1 计算下来的结果不能和之前重复。2.b[i] == -1 那么res - a[i] = b[i] 这里b[i]需要为小于等于k的非负整数。
//如果b里全是-1，那么考虑a里的极差max - min, 那么从max - min ~ k里全部的数都可以作为最小的a[i]s所对应的b[i]（需要考虑max - min > k 的情况）。
