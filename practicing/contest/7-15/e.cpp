#include<bits/stdc++.h>

using ll = long long;

std::vector<std::pair<int, int>> e;
std::map<int, int> mp;
int find(int x) {
    if (x == mp[x]) {
        return x;
    }
    return mp[x] = find(mp[x]);
} 

bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return false;
    }
    mp[x] = y;
    return true;
}
int main() {

    int a, b;
    while (std::cin >> a >> b) {
       if (a == -1 and b == -1) {
            break;
       }

       e.clear();
       mp.clear();
       while (1) {
            if (a == 0 and b == 0) {
                break;
            }
            e.emplace_back(a, b);
            mp[a] = a;
            mp[b] = b;
            std::cin >> a >> b;
        }

        bool ok = true;
        for (auto [x, y] : e) {
            ok &= join(x, y);
        }

        int z;
        bool first = 0;
        for (auto [x, y] : mp) {
            if (!first) {
                if (y) {
                    z = x;
                    first = !first;
                }
            } else {
                if (y != 0 and find(x) != find(z)) {
                    ok = false;
                }
            }
        }

        if (!ok) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
    }

    return 0;
}