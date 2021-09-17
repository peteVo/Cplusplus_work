#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;

ll UCLN(ll x, ll y)
{
    while(y>0){
        ll z=x%y;
        x=y;
        y=z;
    }
    return x;
}

void phanSo(int a, int b, int c, int d)
{
    ll x=(ll)a*d+(ll)c*b,y=(ll)b*d,z=UCLN(x,y);
    x/=z;
    y/=z;
    cout<<x<<" "<<y;
}

int main()
{
    freopen("ird.inp","r",stdin);
    freopen("ird.out","w",stdout);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    phanSo(a,b,c,d);
    return 0;
}
