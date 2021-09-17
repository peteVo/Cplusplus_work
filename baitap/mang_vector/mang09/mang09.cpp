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

bool isSquare(int x)
{
    int y=sqrt(x);
    if(x == y*y) return true;
    else return false;
}

int longestSqrRoad()
{
    int cnt=0,Max=0;
    for(int i=1;i<=n;++i){
        if(isSquare(a[i])) ++cnt;
        else {
            if(Max<cnt) Max=cnt;
            cnt=0;
        }
    }
    return Max;
}

int main()
{
    freopen("mang09.inp","r",stdin);
    freopen("mang09.out","w",stdout);
    ReadData();
    cout<<longestSqrRoad();
    return 0;
}
