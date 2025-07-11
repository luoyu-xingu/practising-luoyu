#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

int main() {
    long long num, q, e, f, g, i, j,v;
    int n;
    cin >> n;
    vector<long long>a(n+1);
    vector<long long>b(n+1);
    for (i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (i = 1;i <= n;i++) {
        cin >> b[i];
    }
    cin >> q;
    while (q--) {
        v = 0;
        cin >> e >> f >> g;
        if (e == 1) {
            a[f] = g;
        }
        if (e == 2) {
            b[f] = g;
        }
        if (e ==3) {
            for (i = f;i <= g;i++)
            {
                v = max(v + a[i], v * b[i]);
            }
            cout << v << endl;
        }
    }
    return 0;
}