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

void Road()
{
    for(int i=1;i<=n;++i){
        if(a[i]<a[i-1]) cout<<"\n"<<a[i]<<" ";
        else cout<<a[i]<<" ";
    }
}

int main()
{
    freopen("mang07.inp","r",stdin);
    freopen("mang07.out","w",stdout);
    ReadData();
    Road();
    return 0;
}
