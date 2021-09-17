#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int biggest(int n)
{
    if(n%3==0) return n/3*7;
    if(n%3==1) return (n-3)/3*7+4;
    if(n%3==2) return n/3*7+1;
}

int main()
{
    freopen("ledlight.inp","r",stdin);
    freopen("ledlight.out","w",stdout);
    int n;
    cin>>n;
    cout<<biggest(n);
    return 0;
}
