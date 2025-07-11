#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

template<const int BIT = 30, typename P = int>
class Trie {
    class Node {
        public:

        std::array<int, 2> nxt;
        int passed,endw;
        int maxd, mind;

        Node () {
            nxt[0] = nxt[1] = passed = endw = 0;
            maxd = -1, mind = inf;
        }
    };

    std::vector<Node> T;

    int newnode() {
        T.emplace_back(Node());
        return T.size() - 1;
    }

    public:

    Trie () {
        T.assign(2, Node());
    }

    void add(P x, int t = 1, int id = 0) {
        int o = 1;
        T[o].passed += t;

        for(int i = BIT; i >= 0; i--) {
            assert(T[o].passed >= 0);
            int b = x >> i & 1;
            if(!T[o].nxt[b]) {
                T[o].nxt[b] = newnode();
            }
            o = T[o].nxt[b];
            T[o].maxd = std::max(T[o].maxd, id);
            T[o].mind = std::min(T[o].mind, id);
            T[o].passed += t;
        }
        assert(T[o].endw + t >= 0);
        T[o].endw += t;
    }

    P querymax(P x) {
        P ans = 0;
        int o = 1;
        for(int i = BIT; i >= 0; i--) {
            int b = x >> i & 1;
            // 用下一个节点的passed信息，因为涉及删除操作，如果删除，节点会复用
            // 由于每个数都添加了BIT + 1 个节点， 因此路一定存在
            if(T[T[o].nxt[b ^ 1]].passed) {
                b ^= 1;
                ans |= (P)1 << i;
            }
            o = T[o].nxt[b];
        }
        return ans;
    }

    P querymin(P x) {
        P ans = 0;
        int o = 1;
        for(int i = BIT; i >= 0; i--) {
            int b = x >> i & 1;
            if(!T[T[o].nxt[b]].passed) {
                b ^= 1;
                ans |= (P)1 << i;
            }
            o = T[o].nxt[b];
        }
        return ans;
    }

    std::pair<int, int> querymin_index(P x) {
        int o = 1;
        for(int i = BIT; i >= 0; i--) {
            int b = x >> i & 1;
            if(!T[T[o].nxt[b]].passed) {
                b ^= 1;
            }
            o = T[o].nxt[b];
        }
        return {T[o].maxd, T[o].mind};
    }

    std::pair<int, int> querymax_index(P x) {
        int o = 1;
        for(int i = BIT; i >= 0; i--) {
            int b = x >> i & 1;
            if(T[T[o].nxt[b ^ 1]].passed) {
                b ^= 1;
            }
            o = T[o].nxt[b];
        }
        return {T[o].maxd, T[o].mind};
    }

};

void solve();

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //std::cin >> t;
    while(t--) solve();
    return 0;
}
void solve(){
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> v(n + 1);
    Trie tr;
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
        tr.add(v[i], 1, i);
    }

    while (q--) {
        int a, b;
        std::cin >> a >> b;
        int max = tr.querymax(a) - b;
        int min = tr.querymin(a) - b;
        if (1LL * max * min > 0) {
            std::cout << -1 << "\n";
        } else {
            auto [x, y] = tr.querymax_index(a);
            if (x > y) {
                std::swap(x, y);
            } 
            auto [o, p] = tr.querymin_index(a);
            if (o > p) {
                std::swap(o, p);
            }

            if (o >= y) {
                y = p;
            } else if (p > x and p >= y) {
                y = p;
            } else if (p > x and p < y) {
                x = p;
            } else {
                x = p;
            }
            assert(x >= 1 and y <= n and y >= x + 1);

            auto f = [&](int x) {
                return (a ^ x) - b;
            };

            //assert(1LL * f(v[x]) * f(v[y]) <= 0);

            while (x + 1 < y) {
                int mid = (x + y) / 2;
                if (1LL * f(v[x]) * f(v[mid]) > 0) {
                    x = mid; 
                } else {
                    y = mid;
                }
            }
            std::cout << x << "\n";
        }
    }
}