#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
ll n, a[1000001];

void ReadData()
{
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
}

ll maxArea()
{
    ll i=1, j=n, area=min(a[i],a[j])*(j-i);
    while(i<j){
        if(a[i]>a[j]){
            j--;
            area=max(area,min(a[i],a[j])*(j-i));
        }
        else{
            i++;
            area=max(area,min(a[i],a[j])*(j-i));
        }
    }
    return area;
}

int main()
{
    freopen("container.inp","r",stdin);
    freopen("container.out","w",stdout);
    ReadData();
    cout<<maxArea();
    return 0;
}
