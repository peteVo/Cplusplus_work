#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int level(int n)
{
    int i,points=0;
    for(i=1;points<n;++i) points+=i;
    i-=1;
    return i;
}

int main()
{
    freopen("gamer.inp","r",stdin);
    freopen("gamer.out","w",stdout);
    int n;
    cin>>n;
    cout<<level(n);
    return 0;
}
