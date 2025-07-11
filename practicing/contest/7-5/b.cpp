#include<bits/stdc++.h>

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int n;
    std::cin >> n;

    int a = n % 10;
    n /= 10;
    int b = n % 10;

    std::cout << b << a << "\n";
}