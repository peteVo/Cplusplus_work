#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n,w,h;
bool xy[101][101];

void Rectsolve(int x1,int y1,int x2,int y2)
{
    if(x1>x2) swap(x1,x2);
    if(y1>y2) swap(y1,y2);
    for(int i=x1+1;i<=x2;++i){
        for(int k=y1+1;k<=y2;++k){
            xy[i][k]=true;
        }
    }
}

void ReadData()
{
    cin>>w>>h>>n;

    int x1,y1,x2,y2;
    for(int i=1; i<=n; ++i){
        cin>>x1>>y1>>x2>>y2;
        Rectsolve(x1,y1,x2,y2);
    }
}

int uncolored()
{
    int cnt=0;
    for(int i=1;i<=w;++i){
        for(int k=1;k<=h;++k){
            if(!xy[i][k]) cnt++;
        }
    }
    return cnt;
}

int main()
{
    freopen("mosaic.inp","r",stdin);
    freopen("mosaic.out","w",stdout);
    ReadData();
    cout<<uncolored();
    return 0;
}
