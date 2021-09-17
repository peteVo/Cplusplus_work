#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int balloons(int n)
{
    int cnt=0, sub=0, i=1;
    while(n>0){
        sub+=i;
        ++cnt;
        n-=sub;
        ++i;
    }
    return cnt;
}

int main()
{
    freopen("balloons.inp","r",stdin);
    freopen("balloons.out","w",stdout);
    int n;
    cin>>n;
    cout<<balloons(n);
    return 0;
}
