#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n, L, x[1001], d[1001], t[1001], v[1001], a[1000001], b[1000001];

void ReadData()
{
    cin>>n>>L;
    for(ll i=1;i<=n;++i) cin>>x[i];
    for(ll i=1;i<=n;++i) cin>>d[i];
    for(ll i=1;i<=n;++i) cin>>t[i];
    for(ll i=1;i<=n;++i) cin>>v[i];
    ll cnt=1;
    for(ll i=1;i<=n;++i){
        for(ll j=1;j<=n;++j){
            a[cnt]=x[i]+d[j];
            ++cnt;
        }
    }
    cnt=1;
    for(ll i=1;i<=n;++i){
        for(ll j=1;j<=n;++j){
            b[cnt]=t[i]+v[j];
            ++cnt;
        }
    }
    cnt=n*n;
    sort(a+1,a+1+cnt);
    sort(b+1,b+1+cnt);
}

ll lower(ll x, ll lo, ll hi)
{
    ll pos=-1, m;
    while(lo<=hi){
        m=(lo+hi)/2;
        if(b[m]>=x){
            if(b[m]==x) pos=m;
            hi=m-1;
        }
        else lo=m+1;
    }
    return pos;
}

ll upper(ll x, ll lo, ll hi)
{
    ll pos=-1, m;
    while(lo<=hi){
        m=(lo+hi)/2;
        if(b[m]<=x){
            if(b[m]==x) pos=m;
            lo=m+1;
        }
        else hi=m-1;
    }
    return pos;
}

ll suitables()
{
    ll cnt=0, m=n*n, low, upp;
    for(ll i=1;i<=m;++i){
        low=lower(L-a[i],1,m);
        upp=upper(L-a[i],1,m);
        if(low>=0 && upp>=0)
            cnt=cnt+upp-low+1;
    }
    return cnt;
}

int main()
{
    freopen("tera.inp","r",stdin);
    freopen("tera.out","w",stdout);
    ReadData();
    cout<<suitables();
    return 0;
}
