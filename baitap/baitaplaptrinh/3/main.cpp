#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int n,d,m[100001];

void trips()
{
    cin>>n>>d;
    for(int i=1;i<=n;++i) cin>>m[i];
    sort(m+1,m+1+n);
    int low=1,cnt=0;
    for(int i=n;i>=1&&i!=low;++i){
        if(m[i]+m[low]<=d){
            cnt++;
            low++;
        }
        else cnt++;
    }
    cout<<cnt<<"\n";
}

int main()
{
    freopen("trip.inp","r",stdin);
    freopen("trip.out","w",stdout);
    trips();
    return 0;
}
