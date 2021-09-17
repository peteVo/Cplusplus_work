#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int maxGroups(int m, int n, int k)
{
    int groups=min(m/2,n), offPeople=n+m-3*groups;
    if(offPeople>=k) return groups;
    else{
        k-=offPeople;
        k=(k+2)/3;
        groups-=k;
    }
    return groups;
}

int main()
{
    freopen("lares.inp","r",stdin);
    freopen("lares.out","w",stdout);
    int m,n,k;
    cin>>m>>n>>k;
    cout<<maxGroups(m,n,k);
    return 0;
}
