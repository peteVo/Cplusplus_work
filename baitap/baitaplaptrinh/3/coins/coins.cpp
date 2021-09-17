#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n,m;

struct pii
{
    ll x,y;
}a[100001];

bool tang(pii t,pii z)
{
    return (t.y-t.x<z.y-z.x);
}

void ReadData()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i].x;
    }
    for(int i=1;i<=n;++i){
        cin>>a[i].y;
    }
    sort(a+1,a+1+n,tang);
}

ll maxCoins()
{
    for(int i=1;i<=n;++i){
        if(m>=(a[i].y-a[i].x)){
            m=m+a[i].x;
        }
        else return m;
    }
    return m;
}

int main()
{
    freopen("coins.inp","r",stdin);
    freopen("coins.out","w",stdout);
    ReadData();
    cout<<maxCoins();
    return 0;
}
