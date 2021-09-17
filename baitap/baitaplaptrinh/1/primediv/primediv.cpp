#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

bool isPrime(ll x)
{
    ll y=sqrt(x);
    for(int i=2;i<=y;++i)
        if(x%i==0) return false;
    return true;
}

void primeDividers(ll n)
{
    ll m=sqrt(n);
    for(int i=2;i<=m;++i){
        if(n%i==0 && isPrime(i)) cout<<i<<" ";
    }
    if(isPrime(n)) cout<<n;
}

int main()
{
    freopen("primediv.inp","r",stdin);
    freopen("primediv.out","w",stdout);
    ll n;
    cin>>n;
    primeDividers(n);
    return 0;
}
