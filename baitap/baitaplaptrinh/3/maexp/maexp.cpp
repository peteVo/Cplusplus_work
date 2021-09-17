#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, a[1001];

ll HighestResult()
{
    cin>>n;
    ll Ori=0,M=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        Ori=Ori+a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;++j){
            ll m;
            if(j-i==1) m=Ori-a[i]-a[j]-a[j+1]+(a[i]*a[j]*a[j+1]);
            else{
                m=Ori-a[i]-a[i+1]-a[j]-a[j+1]+(a[i]*a[i+1]+a[j]*a[j+1]);
            }
            if(m>M) M=m;
        }
    }
    return M;
}

int main()
{
    freopen("maexp.inp","r",stdin);
    freopen("maexp.out","w",stdout);
    cout<<HighestResult();
    return 0;
}
