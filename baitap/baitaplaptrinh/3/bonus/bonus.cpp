#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n, c[100001], sum=0;

void ReadData()
{
    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>c[i];
        sum+=c[i];
    }
}

ll reward()
{
    sort(c+1,c+1+n);
    ll cnt=c[1], minextract=1e9;
    for(ll i=2;i<=n+1;++i){
        if(c[i]!=c[i-1]){
            minextract=min(minextract,cnt);
            cnt=c[i];
        }
        else cnt+=c[i];
    }
    return sum-minextract;
}

int main()
{
    freopen("bonus.inp","r",stdin);
    freopen("bonus.out","w",stdout);
    ReadData();
    cout<<reward();
    return 0;
}
