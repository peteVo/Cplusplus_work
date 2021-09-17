#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll b,k,n,m,dcongdon[50001],pcongdon[50001];

struct pii
{
    ll x,y;
}d[50001], p[50001];

bool giam(pii a, pii b)
{
    return(a.x>b.x);
}

void ReadData()
{
    cin>>b>>k>>n>>m;
    for(ll i=1;i<=n;++i){
        cin>>d[i].x;
        d[i].y=i;
    }
    for(ll i=1;i<=m;++i){
        cin>>p[i].x;
        p[i].y=i;
    }
    sort(d+1,d+1+n,giam);
    sort(p+1,p+1+m,giam);
}

void mangcongdon()
{
    pcongdon[0]=0,dcongdon[0]=0;
    for(ll i=1;i<=n;++i){
        dcongdon[i]=dcongdon[i-1]+d[i].x;
    }
    for(ll i=1;i<=m;++i){
        pcongdon[i]=pcongdon[i-1]+p[i].x;
    }
}

void Solve()
{
    ll posi=0,M=0, j;
    for(int i=0;i<=min(n,k);++i){
        j=k-i;
        if(j>=0 && j<=min(k,m)){
            if(((b+dcongdon[i])*(100+pcongdon[j]))>M){
                posi=i;
                M=(b+dcongdon[i])*(100+pcongdon[j]);
            }
        }
        else{
            j=min(k,m);
            if(((b+dcongdon[i])*(100+pcongdon[j]))>M){
                posi=i;
                M=(b+dcongdon[i])*(100+pcongdon[j]);
            }
        }
    }
    cout<<posi<<" "<<min(k,m+n)-posi<<"\n";
    for(ll i=1;i<=posi;++i){
        cout<<d[i].y<<" ";
    }
    cout<<"\n";
    for(ll i=1;i<=min(k,m+n)-posi;++i){
        cout<<p[i].y<<" ";
    }
}

int main()
{
    freopen("vltk.inp","r",stdin);
    freopen("vltk.out","w",stdout);
    ReadData();
    mangcongdon();
    Solve();
    return 0;
}
