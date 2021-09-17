#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n,k,l[100001],s=0;

bool giam(ll x,ll y)
{
    return x>y;
}

void ReadData()
{
    cin>>n>>k;
    for(ll i=1;i<=n;++i){
        cin>>l[i];
    }
    sort(l+1,l+1+n,giam);
}

bool suit(ll L)
{
    ll cnt=0;
    for(ll i=1;i<=n;++i){
        cnt=cnt+l[i]/L;
    }
    return cnt>=k;
}

ll solve()
{
    ll lo=1, hi=100000000000000;
    while (lo <= hi){
        ll m=(lo+hi)/2;
        if (!suit(m)){
            hi=m-1;
        }
        else{
            lo=m+1;
            s=max(s,m);
        }
    }
    return s;
}

int main()
{
    freopen("wires.inp","r",stdin);
    freopen("wires.out","w",stdout);
    ReadData();
    cout<<solve();
}
