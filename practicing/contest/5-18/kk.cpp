#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

int main() {
    int  n, i, j, a, b, z=INT_MAX,flag=1;
    long long num = -1, l, sum = 0;
    cin >> n;
    for (i = 0;i < n;i++) {
        cin >> a >> b;
        sum += a;
        if (a > b) {
            z = min(z, b);
            flag = 0;
        }
    }
    if (flag ==0)l = sum - z;
    else l = 0;
    cout << l;
    return 0;
}