#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,a[100001],b[100001];

void ReadData()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        cin>>b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
}

int maxPrize()
{
    int cnt=0;
    for(int i=m;i>=1;--i){
        if(b[i]>a[n]) cnt=cnt+n;
        else if(b[i]>a[1]){
            for(int j=1;a[j]<b[i];++j) cnt++;
        }
    }
    return cnt;
}

int main()
{
    freopen("pts.inp","r",stdin);
    freopen("pts.out","w",stdout);
    ReadData();
    cout<<maxPrize();
    return 0;
}
