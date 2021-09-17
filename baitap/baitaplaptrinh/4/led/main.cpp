#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int sticks[10]={6,2,5,5,4,5,6,3,7,6}, maxn[1000001], minn[1000001];

void minNum(int n, int k)
{
    for(int i=1;i<=n;++i){
        for(int j=(i==1);j<=9;++j){
            if(k-sticks[j]>=(n-i)*2 && k-sticks[j]<=(n-i)*7){
                minn[i]=j;
                k=k-sticks[j];
                break;
            }
        }
    }
    for(int i=1;i<=n;++i) cout<<minn[i];
}

void maxNum(int n, int k)
{
    for(int i=1;i<=n;++i){
        for(int j=9;j>=(i==1);--j){
            if(k-sticks[j]>=(n-i)*2 && k-sticks[j]<=(n-i)*7){
                maxn[i]=j;
                k-=sticks[j];
                break;
            }
        }
    }
    for(int i=1;i<=n;++i) cout<<maxn[i];
}

int main()
{
    freopen("led.inp","r",stdin);
    freopen("led.out","w",stdout);
    int n,k;
    cin>>n>>k;
    if(k>=n*2 && k<=n*7){
    minNum(n,k);
    cout<<"\n";
    maxNum(n,k);
    }
    else cout<<"NO SOLUTION";
    return 0;
}
