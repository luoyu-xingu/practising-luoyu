#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while(t--) {
       solve();
    }

    return 0;
}

void solve() {
    ll a, b;
    std::cin >> a >> b;

    ll g = std::gcd(a, b);
    if (a == b) {
        std::cout << 0 << "\n";
        return ;
    }

    if (g == a) {
        std::cout << b << "\n";
    } else if (g != 1) {
        std::cout << std::min(std::lcm(a, b), a + b) << "\n";
    } else {

        ll mina = a, minb = b;
        for (int i = 2; 1LL * i * i <= a; i++) {
            if (a % i == 0) {
                mina = i;
                break;
            }
        }

        for (int i = 2;1LL * i * i <= b; i++) {
            if (b % i == 0) {
                minb = i;
                break;
            }
        }
        //std::cout << mina << ' ' << minb << "\n";
        assert(mina != minb and b % minb == 0 and a % mina == 0);

        // 2 mina, minb, a, b
        std::map<int, bool> vis;
        
        std::map<int, ll> dis;
        dis[2] = dis[mina] = dis[minb] = dis[a] = dis[b] = Inf;
        dis[a] = 0;

        std::priority_queue<std::pair<ll, int>,
                            std::vector<std::pair<ll, int>>,
                            std::greater<std::pair<ll, int>>> pq;

        pq.emplace(0, a);

        while(!pq.empty()) {
            auto [_, u] = pq.top();
            pq.pop();

            if (vis[u]) {
                continue;
            }

            vis[u] = 1;

            if (dis[2] > dis[u] + std::lcm(2, u)) {
                dis[2] = dis[u] + std::lcm(2, u);
                pq.emplace(dis[2], 2);
            }

            if (dis[mina] > dis[u] + std::lcm(mina, u)) {
                dis[mina] = dis[u] + std::lcm(mina, u);
                pq.emplace(dis[mina], mina);
            }

            if (dis[minb] > dis[u] + std::lcm(minb, u)) {
                dis[minb] = dis[u] + std::lcm(minb, u);
                pq.emplace(dis[minb], minb);
            }
        
            if (dis[b] > dis[u] + std::lcm(b, u)) {
                dis[b] = dis[u] + std::lcm(b, u);
                pq.emplace(dis[b], b);
            } 
        }


        std::cout << dis[b] << "\n";
    }
}