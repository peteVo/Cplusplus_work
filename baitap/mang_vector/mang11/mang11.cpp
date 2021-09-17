#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int a[1000001],n,m;

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
}

bool DoiXung(int x, int y)
{
    for(int i=0; i<=(y-x)/2; ++i){
        if(a[x+i]!=a[y-i]) return false;
    }
    return true;
}

int dayDXdainhat()
{
    int Max=1;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            if(DoiXung(i,j) && Max<(j-i+1)) Max=j-i+1;
        }
    }
    return Max;
}

int main()
{
    freopen("mang11.inp","r",stdin);
    freopen("mang11.out","w",stdout);
    ReadData();
    cout<<dayDXdainhat();
    return 0;
}
