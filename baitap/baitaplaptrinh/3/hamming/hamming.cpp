#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n,t, a[1000001];

void ham()
{
    ll i2=1,i3=1,i5=1,i=1;
    a[1]=1;
    while(a[i]<1000000000000000000){
        a[++i]=min(min(a[i2]*2,a[i3]*3),a[i5]*5);
        if(a[i]==a[i2]*2) ++i2;
        if(a[i]==a[i3]*3) ++i3;
        if(a[i]==a[i5]*5) ++i5;
    }
    n=i;
}

ll BinSearch(ll v, ll x)
{
    ll lo = 1, hi = v;
    while (lo <= hi)
    {
        ll m = (lo + hi)/2;
        if (x == a[m]) return m;
        if (x < a[m]) hi = m-1;
        else lo = m+1;
    }
    return -1;
}

void Solve()
{
    ll y;
    for(ll i=1;i<=t;++i){
        cin>>y;
        if(BinSearch(n,y)>0) cout<<BinSearch(n,y)<<"\n";
        else cout<<"Not in sequence\n";
    }
}

int main()
{
    freopen("hamming.inp","r",stdin);
    freopen("hamming.out","w",stdout);
    cin>>t;
    ham();
    Solve();
    return 0;
}
