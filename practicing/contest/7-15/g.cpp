#include<bits/stdc++.h>

using ll = long long;
const int inf = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int l;
    while (std::cin >> l) {
        int N, C, T;
        std::cin >> N >> C >> T;

        int VR, Vt1, Vt2;
        std::cin >> VR >> Vt1 >> Vt2;

        std::vector<int> a(N + 2);
        for (int i = 1; i <= N; i++) {
            std::cin >> a[i];
        }

        a[N + 1] = l;

        std::vector<double> dp(N + 2, 1.0 * inf);
        double O = 1.0 * l / VR;
        dp[0] = -T;
        for (int i = 1; i <= N + 1; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = std::min<double>(dp[i], dp[j] + T + 
                    (((a[i] - a[j]) <= C) ? (1.0 * (a[i] - a[j]) / Vt1) : (1.0 * C / Vt1 + 1.0 * (a[i] - a[j] - C) / Vt2))
                );
            }
        }

        if (dp[N + 1] <= O) {
            std::cout << "What a pity rabbit!\n";
        } else {
            std::cout << "Good job,rabbit!\n";
        }
    }

    return 0;
}
