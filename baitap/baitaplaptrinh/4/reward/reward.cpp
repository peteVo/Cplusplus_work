#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
ll n, rw[200001];
struct pii
{
    ll t,d,dif;
}w[200001];

bool tang1(pii a,pii b)
{
    return(a.t<b.t || (a.t==b.t && a.d>b.d));
}

void ReadData1()
{
    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>w[i].t>>w[i].d;
    }
    sort(w+1,w+1+n,tang1);
}

ll Solve1()
{
    ll rew=0, curtime=0;
    for(ll i=1;i<=n;++i){
        curtime=curtime+w[i].t;
        rew=rew+w[i].d-curtime;
    }
    return rew;
}

/*bool tang2(pii a,pii b)
{
    return(a.dif<b.dif);
}

void ReadData2()
{
    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>w[i].t>>w[i].d;
        w[i].dif=w[i].d-w[i].t;
    }
    sort(w+1,w+1+n,tang2);
}

ll Solve2()
{
    ll rew=0, curtime=0;
    for(ll i=1;i<=n;++i){
        curtime=curtime+w[i].t;
        rew=rew+w[i].d-curtime;
    }
    return rew;
}*/

int main()
{
    freopen("reward.inp","r",stdin);
    freopen("reward.out","w",stdout);
    ReadData1();
    cout<<Solve1();
    return 0;
}
