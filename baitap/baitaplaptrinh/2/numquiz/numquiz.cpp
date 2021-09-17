#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n, a[100001];

void ReadData()
{
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
}

int UCLN(int x,int y)
{
    int z;
    while(y>0){
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}

int Sum()
{
    int M=0;
    for(int i=1; i<=n; i++){
        M=UCLN(M,a[i]);
    }
    long long s=(long long)M*n;
    return s;
}

int main()
{
    freopen("numquiz.inp","r",stdin);
    freopen("numquiz.out","w",stdout);
    ReadData();
    cout<<Sum();
    return 0;
}
