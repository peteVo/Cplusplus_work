#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
int n,l[200001];
void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>l[i];
    sort(l+1,l+1+n);
}

int cost(int pos)
{
    int sum=0;
    for(int i=1;i<=n;++i){
        sum=sum+abs(l[pos]-l[i]);
    }
    return sum;
}

int mincost()
{
    return min(cost(n/2),cost(n/2+1));
}

int main()
{
    freopen("stickslen.inp","r",stdin);
    freopen("stickslen.out","w",stdout);
    ReadData();
    cout<<mincost();
    return 0;
}
