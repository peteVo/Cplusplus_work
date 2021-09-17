#include <iostream>
#include <cmath>
#include <cstdio>

typedef long long ll;
using namespace std;

ll milk(ll a, ll n, ll C)
{
    ll s=0;
    s=(C/a)+(C/a)/n;
    return s;
}

int main()
{
    freopen("buymilk.inp","r",stdin);
    freopen("buymilk.out","w",stdout);
    ll a,n,C;
    cin>>a;
    cin>>n;
    cin>>C;
    cout<<milk(a,n,C);
    return 0;
}
