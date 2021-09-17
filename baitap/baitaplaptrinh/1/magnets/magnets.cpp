#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n,a[100001];

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
}

int numGroups()
{
    int cnt=1;
    for(int i=2;i<=n;++i){
        if(a[i]!=a[i-1]) ++cnt;
    }
    return cnt;
}

int main()
{
    freopen("magnets.inp","r",stdin);
    freopen("magnets.out","w",stdout);
    ReadData();
    cout<<numGroups();
    return 0;
}
