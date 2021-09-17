#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, k, a[100001];

bool giam(ll x,ll y)
{
    return (x>y);
}

ll maxValue()
{
    cin>>n>>k;
    ll b;
    cin>>b;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    ll M=b;
    sort(a+1,a+n,giam);
    for(int i=1;i<n;i++){
        if(i-1<k) M=M+a[i];
        else M=M-a[i];
    }
    return M;
}

int main()
{
    freopen("express.inp","r",stdin);
    freopen("express.out","w",stdout);
    cout<<maxValue();
    return 0;
}
