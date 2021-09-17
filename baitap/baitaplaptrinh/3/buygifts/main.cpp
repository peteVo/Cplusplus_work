#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,a[100001],b[100001];

int ReadData()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n-m+1;i++){
        b[i]=a[i+m-1]-a[i];
    }
    int M=1000000000;
    for(int i=1;i<=n-m+1;i++){
        M=min(M,b[i]);
    }
    return M;
}

int main()
{
    freopen("buygifts.inp","r",stdin);
    freopen("buygifts.out","w",stdout);
    cout<<ReadData();
    return 0;
}
