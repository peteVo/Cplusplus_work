#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int promotion(int n,int k)
{
    int s=0;
    while(n>=k){
        n=n-k+1;
        s++;
    }
    return s;
}

int main()
{
    freopen("promotion.inp","r",stdin);
    freopen("promotion.out","w",stdout);
    int n,k;
    cin>>n;
    cin>>k;
    cout<<promotion(n,k);
    return 0;
}
