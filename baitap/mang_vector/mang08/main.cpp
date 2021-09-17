#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int a[1000001],n;

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    a[0]=-1e7;
}

int LongestRoad()
{
    int cnt=0, Max=0;
    for(int i=1;i<=n;++i){
        if(a[i]<a[i-1]){
            if(Max<cnt) Max=cnt;
            cnt=1;
        }
        else ++cnt;
    }
    return Max;
}

int main()
{
    freopen("mang08.inp","r",stdin);
    freopen("mang08.out","w",stdout);
    ReadData();
    cout<<LongestRoad();
    return 0;
}
