#include <iostream>
#include <vector>
#include<string>
using namespace std;
int main() {
    int a, b, c, d, e;
    int p[100] = { 0 };
    long long sum = 0;
    cin >> e;
    string t;
    cin >> t;
    string s = t;
    while (s.find("lose") != string::npos)
    {
        s.erase(s.find("lose"), 4);
        sum++;
        p[0]++;
    }
    s = t;
    while ((s.find("ose") != string::npos) && e) {
        s.erase(s.find("ose"), 3);
        e--;
        p[1]++;
    }
    sum += p[1] - p[0];
    if (!e) {
        cout << sum;
        return 0;
    }
     s = t;
    while ((s.find("lse") != string::npos) && e) {
        s.erase(s.find("lse"), 3);
        e--;
        p[2]++;
    }  sum += p[2];
    if (!e) {
        cout << sum;
        return 0;
    } s = t;
    while ((s.find("los") != string::npos)&& e) {
        s.erase(s.find("los"), 3);
        e--;
        p[3]++;
    } sum += p[3] - p[0];
    if (!e) {
        cout << sum;
        return 0;
    } s = t;
    while ((s.find("loe") != string::npos) && e) {
        s.erase(s.find("loe"), 3);
        e--;
        p[4]++;
    } sum += p[4] ;
    if (!e) {
        cout << sum;
        return 0;
    } s = t;
    while ((s.find("lo") != string::npos) && e > 1) {
        s.erase(s.find("lo"), 2);
        e -= 2;
        p[6]++;
    } sum += p[6] - p[3]-p[4];
    if (e <= 0) {
        cout << sum;
        return 0;
    } s = t;
    while ((s.find("ls") != string::npos) && e > 1) {
        s.erase(s.find("ls"), 2);
        e -= 2;
        p[7]++;
    } sum += p[7] - p[2];
    if (e <= 0) {
        cout << sum;
        return 0;
    }s = t;
    while ((s.find("le") != string::npos) && e > 1) {
        s.erase(s.find("le"), 2);
        e -= 2;
        sum++;
        p[8]++;
    }if (e <= 0) {
        cout << sum;
        return 0;
    } s = t;
    while ((s.find("os") != string::npos)&& e > 1) {
        s.erase(s.find("os"), 2);
        e -= 2;
        p[9]++;
    }
    sum += p[9] - p[1]-p[3];
    if (e <= 0) {
        cout << sum;
        return 0;
    }s = t;
    while ((s.find("oe") != string::npos) && e > 1) {
        s.erase(s.find("oe"), 2);
        e -= 2;
        p[10]++;
    }
    sum += p[10] - p[4];
    if (e <= 0) {
        cout << sum;
        return 0;
    }s = t;
    while ((s.find("se") != string::npos) && e > 1) {
        s.erase(s.find("se"), 2);
        e -= 2;
        p[11]++;
    } sum += p[11] - p[1]-p[2];
    if (e <= 0) {
        cout << sum;
        return 0;
    } s = t;
    while ((s.find("l") != string::npos) && e > 2) {
        s.erase(s.find("l"), 1);
        e -= 3;
        p[12]++;
    }
    sum += p[12] - p[6]-p[7]-p[8];
        if (e <= 0) {
        cout << sum;
        return 0;
    } s = t;
    while ((s.find("o") != string::npos) && e > 2) {
        s.erase(s.find("o"), 1);
        e -= 3;
        p[13]++;
    }
    sum += p[13]- p[6] - p[9] - p[10];
    if (e <= 0) {
        cout << sum;
        return 0;
    }s = t;
    while ((s.find("s") != string::npos) && e > 2) {
        s.erase(s.find("s"), 1);
        e -= 3;
        p[14]++;
    }
    sum += p[14]-p[7] - p[9] - p[11];
    if (e <= 0) {
        cout << sum;
        return 0;
    }
    s = t;
    while ((s.find("e") != string::npos) &&e > 2) {
        s.erase(s.find("e"), 1);
        e -= 3;
        p[15]++;
    }
    sum += p[15] - p[8]-p[10]-p[11];
    if (e <= 0) {
        cout << sum;
        return 0;
    }
    e /= 4;
    sum += e;
    cout << sum;
    return 0;
}