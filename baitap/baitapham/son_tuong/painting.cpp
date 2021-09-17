#include <iostream>
#include <cmath>
#include <cstdio>

typedef long long ll;
using namespace std;

ll soUoc(ll n)
{
    ll m = sqrt(n), s, i;
    if(n != m*m) s=0;
    else s=-1;
    for(i=1;i<=m;++i){
        if((n%i)==0) s+=2;
    }
    return s;
}

void painting(ll n)
{
    ll den = soUoc(n),trang = n - den;
    cout<<trang<<" "<<den;
}

int main()
{
    freopen("painting.inp","r",stdin);
    freopen("painting.out","w",stdout);
    ll n;
    cin>>n;
    painting(n);
    return 0;
}
