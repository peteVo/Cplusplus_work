#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n,m,k,a[200001],b[200001];

void ReadData()
{
    cin>>n>>m>>k;
    for(ll i=1;i<=n;++i) cin>>a[i];
    for(ll i=1;i<=m;++i) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
}

ll maxCustomers()
{
    if(k>=5e8) return min(n,m);
    ll i=1,j=1,cnt=0;
    while(i<=n && j<=m){
        if(b[j]>=(a[i]-k) && b[j]<=(a[i]+k)){
            cnt++;
            i++;
            j++;
        }
        else if(b[j]<(a[i]-k)) j++;
        else i++;
    }
    return cnt;
}

int main()
{
    freopen("appartments.inp","r",stdin);
    freopen("appartments.out","w",stdout);
    ReadData();
    cout<<maxCustomers();
    return 0;
}

