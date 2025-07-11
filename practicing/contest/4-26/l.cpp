#include<bits/stdc++.h>
using namespace std;
int main()
{
    multimap<int,int> spi;
    multimap<int,int> sou;
    int n,a,b,c,d;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a>>b>>c>>d;
        if (c&d)
            if (a>b)
                sou.insert({b,i});
            else spi.insert({a,i});
        else if (c)
            spi.insert({a,i});
        else sou.insert({b,i});
    }
    cout<<spi.size();
    for (auto i:spi)
        cout<<" "<<i.second;
    cout<<endl;
    cout<<sou.size();
    for (auto i:sou)
        cout<<" "<<i.second;
    return 0; 
}