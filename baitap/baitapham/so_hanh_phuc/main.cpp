#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int k(int n)
{
    int x = 0;
    while (n>0){
        n/=10;
        ++x;
    }
    return x;
}

bool isSHP(int n)
{
    int a = k(n);
    if (a%2!=0) return false;
    int S1=0,S2=0,i;
    for(i=1;i<=a;++i){
        if(i<=a/2) S1+=n%10;
        else S2+=n%10;
        n=n/10;
    }
    return (S1==S2);
}

void sohanhphuc(int n)
{
    int i;
    for(i=11;i<=n;++i){
        if(isSHP(i)) cout<<i<<"\n";
    }
}

int main()
{
    freopen("hnum.inp","r",stdin);
    freopen("hnum.out","w",stdout);
    int n;
    cin>>n;
    sohanhphuc(n);
    return 0;
}
