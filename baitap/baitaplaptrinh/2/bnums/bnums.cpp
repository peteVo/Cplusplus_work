#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int a[1000000];

bool isBNum(int n)
{
    int i=0,k=0;
    while(n>0){
        i++;
        k+=n%10;
        n/=10;
    }
    return (k%i==0);
}

void ReadData()
{
    int k=0;
    for(int i=1;i<=1000000;i++){
        k++;
        while(!isBNum(k)) k++;
        a[i]=k;
    }
}

void Solve()
{
    int x;
    while(cin>>x){
        cout<<a[x]<<"\n";
    }
}

int main()
{
    freopen("bnums.inp","r",stdin);
    freopen("bnums.out","w",stdout);
    ReadData();
    Solve();
    return 0;
}
