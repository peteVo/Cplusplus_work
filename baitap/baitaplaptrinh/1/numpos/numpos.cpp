#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

long long position(int k)
{
    if(k<=2) return k;
    else return (long long)(k-2)*3;
}

int main()
{
    freopen("numpos.inp","r",stdin);
    freopen("numpos.out","w",stdout);
    int k;
    cin>>k;
    cout<<position(k);
    return 0;
}
