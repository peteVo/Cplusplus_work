#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int a[1000001], n;

int mostDiffer()
{
    int delta=2000000;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<n;++i){
        if(abs(a[i]-a[i+1])<delta) delta=abs(a[i]-a[i+1]);
    }
    return delta;
}

int main()
{
    freopen("mang02.inp","r",stdin);
    freopen("mang02.out","w",stdout);
    cout<<mostDiffer();
    return 0;
}
