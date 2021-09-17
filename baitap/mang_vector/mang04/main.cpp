#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int a[1000001], n;

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
}

int MinVal(int avoid)
{
    int Min = 1e7;
    for(int i = 1; i<= n; ++i){
        if(a[i] != avoid && a[i]< Min)
            Min = a[i];

    }
    return Min;
}

int main()
{
    freopen("mang04.inp","r",stdin);
    freopen("mang04.out","w",stdout);
    ReadData();
    int v1 = MinVal(1e7);
    int v2 = MinVal(v1);
    if(v1==1e7) cout<<-1<<" ";
    else cout<<v1<<" ";
    if(v2==1e7) cout<<-1;
    else cout<<v2;
    return 0;
}



