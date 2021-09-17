#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll S, a[10001],b[10001];

void Dist(ll S)
{
    cin>>S;
    ll n,cnt=0;
    for(n=sqrt(2*S);n>=1;--n){
        if((2*S-n*n+n)%(2*n)==0){
            cnt++;
            a[cnt]=(2*S-n*n+n)/(2*n);
            b[cnt]=a[cnt]+n-1;
        }
    }
    cout<<cnt<<"\n";
    for(int i=1;i<=cnt;++i) cout<<a[i]<<" "<<b[i]<<"\n";
}

int main()
{
    freopen("sum.inp","r",stdin);
    freopen("sum.out","w",stdout);
    Dist(S);
    return 0;
}
