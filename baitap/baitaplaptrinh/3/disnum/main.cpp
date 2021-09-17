#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int n, a[100001];

void ReadData()
{
    cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
    }
}

void Sort()
{
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            if(a[i]>=a[j]) swap(a[i],a[j]);
        }
    }
}

int differNum()
{
    sort(a+1,a+1+n);
    int x=1000000001, cnt=0;
    for(int i=1; i<=n; ++i){
        if(x!=a[i]){
            x=a[i];
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    freopen("disnum.inp","r",stdin);
    freopen("disnum.out","w",stdout);
    ReadData();
    cout<<differNum();
    return 0;
}
