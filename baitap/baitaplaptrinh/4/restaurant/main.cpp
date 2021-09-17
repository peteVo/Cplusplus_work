#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n;
struct pii
{
    ll x,y;
}a[400001];

bool tang(pii t,pii z)
{
    return(t.x<z.x || (t.x==z.x && t.y<z.y));
}

void ReadData()
{
    cin>>n;
    for(ll i=1;i<=2*n;i=i+2){
        cin>>a[i].x>>a[i+1].x;
        a[i].y=0;
        a[i+1].y=1;
    }
    sort(a+1,a+1+2*n,tang);
}

ll maxGuests()
{
    ll in=0,m=0;
    for(ll i=1;i<=n*2;++i){
        if(a[i].y==0) in++;
        else in--;
        m=max(m,in);
    }
    return m;
}

int main()
{
    freopen("restaurant.inp","r",stdin);
    freopen("restaurant.out","w",stdout);
    ReadData();
    cout<<maxGuests();
    return 0;
}
