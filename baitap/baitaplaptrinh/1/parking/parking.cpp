#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

long long parkingStoppers(int n,int m)
{
    long long theoreticalSlots=(long long)(n+n%2)*(m+m%2), collars=theoreticalSlots/4;
    return collars;
}


int main()
{
    freopen("parking.inp","r",stdin);
    freopen("parking.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cout<<parkingStoppers(n,m);
    return 0;
}
