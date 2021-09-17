#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>


using namespace std;

int n,a[100001];

bool giam(int x,int y)
{
    return (x>y);
}

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,giam);
}

int minMoney()
{
    int cnt=0, pos=3;
    while(n-pos>=0){
        cnt=cnt+a[pos-2]+a[pos-1];
        pos+=3;
    }
    if(n-pos==-1) cnt=cnt+a[n]+a[n-1];
    if(n-pos==-2) cnt=cnt+a[n];
    return cnt;
}

int main()
{
    freopen("book.inp","r",stdin);
    freopen("book.out","w",stdout);
    ReadData();
    cout<<minMoney();
    return 0;
}
