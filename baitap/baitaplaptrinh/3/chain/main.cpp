#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
ll n, a[100001];

ll connections()
{
    cin>>n;
    ll i;
    for(i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll s=0;
    for(i=1;i<=n;++i){
        s=s+a[i];
        if(s>=n-i-1) break;
    }
    if(s==n-i-1) return s;
    else return n-1;
}

int main()
{
    freopen("chain.inp","r",stdin);
    freopen("chain.out","w",stdout);
    cout<<connections();
    return 0;
}
