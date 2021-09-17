#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n,c;

struct pii
{
    ll x,y;
}a[100001];

bool tang(pii t,pii z)
{
    return (t.x<z.x);
}

void ReadData()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
}

ll MaxWork()
{
    sort(a+1,a+1+n,tang);
    ll skill=c, works=0;
    for(int i=1;i<=n;++i){
        if(skill>=a[i].x){
            skill=skill+a[i].y;
            works++;
        }
        else return works;
    }
    return works;
}

int main()
{
    freopen("olympic.inp","r",stdin);
    freopen("olympic.out","w",stdout);
    ReadData();
    cout<<MaxWork();
    return 0;
}
