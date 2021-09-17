#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

ll kPosDiv(ll n,ll k)
{
    for(int i=1;i<=n;++i){
        if(n%i==0) --k;
        if(k==1) return i;
    }
    return -1;
}

int main()
{
    freopen("kthdiv.inp","r",stdin);
    freopen("kthdiv.out","w",stdout);
    ll n,k;
    cin>>n>>k;
    cout<<kPosDiv(n,k);
    return 0;
}
