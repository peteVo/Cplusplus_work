#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

long long hives(long long n)
{
    long long s=1;
    for(int i=2; i<=n; ++i){
        s=s+(i-1)*6;
    }
    return s;
}

int main()
{
    freopen("beehive.inp","r",stdin);
    freopen("beehive.out","w",stdout);
    long long n;
    cin>>n;
    cout<<hives(n);
    return 0;
}
