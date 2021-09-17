#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n,K,t[200001];

void ReadData()
{
    cin>>n>>K;
    for(ll i=1;i<=n;++i) cin>>t[i];
    sort(t+1,t+1+n);
}

bool check(ll x)
{
    ll cnt=0;
    for(ll i=1;i<=n;++i){
        cnt=cnt+x/t[i];
        if(cnt>=K) return true;
    }
    return false;
}

ll lowestPossibleTime()
{
    ll lo=1, hi=1e18, ans;
    while(lo<=hi){
        ll m=(lo+hi)/2;
        if(check(m)){
            ans=m;
            hi=m-1;
        }
        else lo=m+1;
    }
    return ans;
}

int main()
{
    freopen("machines.inp","r",stdin);
    freopen("machines.out","w",stdout);
    ReadData();
    cout<<lowestPossibleTime();
    return 0;
}
