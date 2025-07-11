#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a, b, c, d, e, f, i, j;
    long long sum = 1;
    cin >> a;
    vector<vector<int>>p(a + 1, vector<int>(a + 1));
    for (i = 1;i <= a;i++) {
        for (j = 1;j <= a;j++) {
            if((i+j==a+1)||(i+j==a+2))sum+= (i - 1) * a + j;
        }
    }
    cout << sum;
    return 0;
}