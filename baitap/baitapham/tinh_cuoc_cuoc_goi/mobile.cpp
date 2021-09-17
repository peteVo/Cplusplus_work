#include <iostream>
#include <cmath>
#include <cstdio>

typedef long long ll;
using namespace std;

ll mobile(ll p,ll t,ll n)
{
    long long s = (n/60)*p + (((n%60)+5)/6)*t;
    return s;
}

int main()
{
    freopen("mobile.inp","r",stdin);
    freopen("mobile.out","w",stdout);
    ll p,t,n;
    cin>>p;
    cin>>t;
    cin>>n;
    cout<<mobile(p,t,n);
    return 0;
}
