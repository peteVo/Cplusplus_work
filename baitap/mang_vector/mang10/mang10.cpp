#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int a[2000001],n,m;

void ReadData()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=n+1; i<=2*n; ++i) a[i]=a[i-n];
}

void DichChuSo()
{
    m = m%n;
    for(int i=m+1;i<=m+n;++i) cout<<a[i]<<" ";
}

int main()
{
    freopen("mang10.inp","r",stdin);
    freopen("mang10.out","w",stdout);
    ReadData();
    DichChuSo();
    return 0;
}
