#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int intersect(int x1, int x2, int x3, int x4)
{
    x1=max(x1,x3);
    x2=min(x2,x4);
    if(x1>=x2) return 0;
    else return x2-x1;
}

void solve()
{
    int n, x1, y1, x2, y2, x3, y3, x4, y4;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        if(x3>x4) swap(x3,x4);
        if(y3>y4) swap(y3,y4);
        int x=intersect(x1,x2,x3,x4);
        int y=intersect(y1,y2,y3,y4);
        cout<<(long long)x*y<<"\n";
    }
}

int main()
{
    freopen("intersec.inp","r",stdin);
    freopen("intersec.out","w",stdout);
    solve();
    return 0;
}
