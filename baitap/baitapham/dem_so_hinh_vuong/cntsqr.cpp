#include <iostream>
#include <cmath>
#include <cstdio>

typedef long long ll;

using namespace std;

ll ksqrcount(int k,ll n,ll m)
{
    ll s=(n-k+1)*(m-k+1);
    return s;
}

ll sqrcount(ll n,ll m)
{
    int k;
    ll s=0;
    for(k=1;k<=n && k<=m;++k){
        s+=ksqrcount(k,m,n);
    }
    return s;
}

int main()
{
    freopen("cntsqr.inp","r",stdin);
    freopen("cntsqr.out","w",stdout);
    ll n,m;
    cin>>n;
    cin>>m;
    cout<<sqrcount(n,m);
    return 0;
}
