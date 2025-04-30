#include<bits/stdc++.h>

using ll = long long;

std::array<int, 8> dx = {1, -1, 0, 0, 1, -1, 1, -1};
std::array<int, 8> dy = {0, 0, 1, -1, 1, -1, -1, 1};

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;
class Trie {
    class node {
        public:
        std::array<int, 26> nxt;
        int passed, endw;
        node() {
            passed = endw = 0;
            for (int i = 0; i < 26; i++) {
                nxt[i] = 0;
            }
        }
    };

    std::vector<node> T;

    int newnode() {
        T.emplace_back();
        return T.size() - 1;
    }
    public:
    Trie() {
        T.assign(2, node());
    }

    void add(std::string s) {
        int o = 1;
        //T[o].passed++;
        for (auto c : s) {
            int q = c - 'a';
            if (!T[T[o].nxt[q]].passed) {
                T[o].nxt[q] = newnode();
            }
            T[o].passed++;
            o = T[o].nxt[q];
        }
        T[o].passed++;
        T[o].endw++;
    }

    int queryY(std::string s) {
        std::vector<int> id;
        int o = 1;
        id.push_back(1);
        for (auto c : s) {
            int q = c - 'a';
            if (!T[T[o].nxt[q]].passed) {
                return 0;
            }  
            o = T[o].nxt[q];
            id.push_back(o);  
        }
        int res = T[o].passed;

        for (auto x : id) {
            T[x].passed -= res;
            assert(T[o].passed >= 0);
        }
        return res;
    }

    bool queryX(std::string s) {
        int o = 1;
        for (auto c : s) {
            int p = c - 'a';
            if (!T[o].nxt[p]) {
                return false;
            }
            o = T[o].nxt[p];
            if(T[o].endw) {
                return true;
            }
        }
        return false;
    }
};
void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(15);

    int t = 1;
//    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve(){
    int q;
    std::cin >> q;

    Trie X, Y;
    int ans = 0;
    while (q--) {
        int op;
        std::string s;
        std::cin >> op >> s;
        if (op == 1) {
            X.add(s);
            ans -= Y.queryY(s);
        } else {
            if (!X.queryX(s)) {
                ans++;
                Y.add(s);
            }
        }
        std::cout << ans << "\n";
    }
    
}
