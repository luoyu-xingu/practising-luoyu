#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

template<typename P = int, const int BIT = 30>
class Trie {
    class Node {
        public:

        std::array<int, 2> nxt;
        int passed,endw;

        Node () {
            nxt[0] = nxt[1] = passed = endw = 0;
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

    void add(P x, int t = 1) {
        int o = 1;
        T[o].passed += t;

        for(int i = BIT; i >= 0; i--) {
            assert(T[o].passed >= 0);
            int b = x >> i & 1;
            if(!T[o].nxt[b]) {
                T[o].nxt[b] = newnode();
            }
            o = T[o].nxt[b];
            T[o].passed += t;
        }
        assert(T[o].endw + t >= 0);
        T[o].endw += t;
    }

    P query(P x) {
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
};

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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);

    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    Trie tr;
    int ans = n + 1;

    for(int i = 0, j = 0; i < n; i++) {
        tr.add(a[i], 1);
        //std::cout << tr.query(a[i]) << '\n';
        while(j <= i and tr.query(a[i]) >= k) {
            ans = std::min(ans, i - j + 1);
            tr.add(a[j], -1);
            j++;
        }
    }

    if(ans == n + 1) {
        std::cout << -1 << '\n';
    }
    else {
        std::cout << ans << '\n';
    }
}