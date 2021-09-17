#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

ll reverseNum(ll x)
{
    ll y=0;
    while(x>0)
    {
        y=y*10+x%10;
        x/=10;
    }
    return y;
}

ll DX(ll n)
{
    while(n!=reverseNum(n)){
        n+=reverseNum(n);
    }
    return n;
}

int main()
{
    freopen("palnum.inp","r",stdin);
    freopen("palnum.out","w",stdout);
    ll n;
    cin>>n;
    cout<<DX(n);
    return 0;
}
