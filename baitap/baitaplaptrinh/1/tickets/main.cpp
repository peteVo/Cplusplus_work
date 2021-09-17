#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;

ll minMoney(ll n,ll k,ll p1,ll p2)
{
    if(p1*k<p2) return p1*n;
    ll promo=n/k*p2;
    if((n%k)*p1>p2) return promo+p2;
    return promo+(n%k)*p1;
}

int main()
{
    freopen("tickets.inp","r",stdin);
    freopen("tickets.out","w",stdout);
    ll n,k,p1,p2;
    cin>>n>>k>>p1>>p2;
    cout<<minMoney(n,k,p1,p2);
    return 0;
}
