#include<bits/stdc++.h>

using ll = long long;

class Point {
    public:
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    Point(const Point &rhs) {
        x = rhs.x;
        y = rhs.y;
    }

    friend bool operator== (const Point &self, const Point &rhs) {
        return self.x == rhs.x and self.y == rhs.y;
    }
};

class Line {
    // 两点定线
    Point a, b;
    public:
    Line() {}
    Line(const Point &x, const Point &y) {
        if (x == y) {
            std::cout << "Same Point!" << "\n";
            assert(false);
        }
        a = x;
        b = y;
    }
    Line(const Line &rhs) {
        a = rhs.a;
        b = rhs.b;
    }

    bool isline(const Point &c) {
        return 1LL * (b.y - a.y) * (c.x - a.x) == 1LL * (c.y - a.y) * (b.x - a.x);
    }

};

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {

    // C 300 2 * 300
    int n, k;
    std::cin >> n >> k;

    std::vector<Point> p(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i].x >> p[i].y;
    }

    if (k == 1) {
        std::cout << "Infinity" << "\n";
        return;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            Line l(p[i], p[j]);
            std::vector<int> v;
            for (int i = 1; i <= n; i++) {
                if (l.isline(p[i])) {
                    v.push_back(i);
                }
            }
            if (v.size() >= k and v[0] == i and v[1] == j) {
                ans++;
            }
        }
    }
    std::cout << ans << "\n";

}

