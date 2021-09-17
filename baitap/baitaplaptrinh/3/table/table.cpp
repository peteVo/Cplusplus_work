#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

void minPerimeter(ll n)
{
    ll m=sqrt(n);
    if(n%m==0 && n/m==m) cout<<m<<" "<<m;
    else{
        if(2*(2*m+2)<=2*(m+n/m+1)) cout<<m+1<<" "<<m+1;
        else cout<<m<<" "<<n/m+1;
    }
}

int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    ll n;
    cin>>n;
    minPerimeter(n);
    return 0;
}
