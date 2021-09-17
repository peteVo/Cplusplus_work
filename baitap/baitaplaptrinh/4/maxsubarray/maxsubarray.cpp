#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n,a[200001];

void ReadData()
{
    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
    }
}

ll LargestArray() {
    ll best = -1000000000, sum = 0;
    for (ll i=1; i<=n; ++i) {
        sum = max(a[i],sum + a[i]);
        best = max(best,sum);
    }
    return best;
}

int main()
{
    freopen("maxsubarray.inp","r",stdin);
    freopen("maxsubarray.out","w",stdout);
    ReadData();
    cout<<LargestArray();
    return 0;
}
