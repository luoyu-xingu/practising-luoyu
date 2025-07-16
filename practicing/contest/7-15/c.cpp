#include<bits/stdc++.h>

using ll = long long;

const int inf = 0x3f3f3f3f;
const ll  Inf = 0x3f3f3f3f3f3f3f3f;
int op;

void solve();

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    //std::cin >> t;

    while(std::cin >> op) {
       solve();
    }

    return 0;
}

void solve() {
    if (op == 1) {
        std::string s;
        std::cin >> s;

        if (s == "ADD") {
            std::cout << "000001";
        } else if (s == "SUB") {
            std::cout << "000010";
        } else if (s == "DIV") {
            std::cout << "000011";
        } else if (s == "MUL") {
            std::cout << "000100";
        } else if (s == "MOVE") {
            std::cout << "000101";
        } else {
            std::cout << "000110";
            char c;
            std::cin >> c;
            int x;
            std::cin >> x;
            for (int i = 4; i >= 0; i--) {
                if ((x >> i) & 1) {
                    std::cout << "1";
                } else {
                    std::cout << "0";
                }
            }
            for (int i = 1; i <= 5; i++) {
                std::cout << 0;
            }
            std::cout << "\n";
            return;
        } 

        char c;
        std::cin >> c;
        int x;
        std::cin >> x;
        for (int i = 4; i >= 0; i--) {
            if ((x >> i) & 1) {
                std::cout << "1";
            } else {
                std::cout << "0";
            }
        }

        std::cin >> c;
        std::cin >> c;
        std::cin >> x;
        //std::cout << x << "\n";
        for (int i = 4; i >= 0; i--) {
            if ((x >> i) & 1) {
                std::cout << "1";
            } else {
                std::cout << "0";
            }
        }
        std::cout << "\n";
    } else {
        std::string s;
        std::cin >> s;
        if (s.size() != 16) {
            std::cout << "Error!\n";
            return;
        }
        auto a = s.substr(0, 6);
        auto check = [&]() {
            int ans = 0;
            for (int i = 6; i <= 10; i++) {
                if (s[i] != '0' && s[i] != '1') {
                    return false;
                }
                ans += (s[i] - '0') << (10 - i);
            }
            if (ans == 0) {
                return false;
            }
            ans = 0;
            for (int i = 11; i <= 15; i++) {
                ans += (s[i] - '0') << (15 - i);
            }
            if (ans == 0) {
                return false;
            }
            return true;

        };
        if (a == "000001") {
            if (!check()) {
                std::cout << "Error!\n";
                return;
            }
            std::cout << "ADD ";
        } else if (a == "000010" ) {
            if (!check()) {
                std::cout << "Error!\n";
                return;
            }
            std::cout << "SUB ";
        } else if (a == "000011") {
            if (!check()) {
                std::cout << "Error!\n";
                return;
            }
            std::cout << "DIV ";
        } else if (a == "000100") {
            if (!check()) {
                std::cout << "Error!\n";
                return;
            }
            std::cout << "MUL ";
        } else if (a == "000101") {
            if (!check()) {
                std::cout << "Error!\n";
                return;
            }
            std::cout << "MOVE ";
        } else if (a == "000110") {
            int res = 0;
            for (int i = 6; i <= 10; i++) {
                if (s[i] != '0' and s[i] != '1') {
                    std::cout << "Error!\n";
                    return;
                }
                res += (s[i] - '0') << (10 - i);
            }

            if (res == 0) {
                std::cout << "Error!\n";
                return ;
            }
            for (int i = 11; i <= 15; i++) {
                if (s[i] != '0') {
                    std::cout << "Error!\n";
                    return;
                }
            }
            std::cout << "SET ";
            int ans = 0;
            for (int i = 6; i <= 10; i++) {
                ans += (s[i] - '0') << (10 - i);
            }
            std::cout << "R";
            std::cout << ans << "\n";

            return;
        } else {
            std::cout << "Error!\n";
            return;
        }

        int ans = 0;
        for (int i = 6; i <= 10; i++) {
            ans += (s[i] - '0') << (10 - i);
        }
        std::cout << "R";
        std::cout << ans << ",";
        ans = 0;
        for (int i = 11; i <= 15; i++) {
            ans += (s[i] - '0') << (15 - i);
        }
        std::cout << "R";
        std::cout << ans << "\n";

    }
}
