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
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
}

ll smallestSum()
{
    ll sum=0;
    for(int i=1;i<=n;++i){
        if(a[i]<=sum+1 && a[i]>=1) sum+=a[i];
        else return sum+1;
    }
}

int main()
{
    freopen("anasum.inp","r",stdin);
    freopen("anasum.out","w",stdout);
    ReadData();
    cout<<smallestSum();
    return 0;
}
