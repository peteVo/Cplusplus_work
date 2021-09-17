#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;


ll squareval(ll x,ll y)
{
    ll k=x+y-1, firstval=k*(k-1)/2+1;
    return firstval+y-1;
}

void Pos(ll z)
{
    ll k=1,i=1;
    while(z>i){
        i=i+k+1;
        k++;
    }
    ll firstval=k*(k-1)/2+1, y=z-firstval+1, x=k-y+1;
    cout<<x<<" "<<y;
}

int main()
{
    freopen("mapping.inp","r",stdin);
    freopen("mapping.out","w",stdout);
    int x,y,z;
    cin>>x>>y>>z;
    cout<<squareval(x,y)<<"\n";
    Pos(z);
    return 0;
}
