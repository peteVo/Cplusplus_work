#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int d(int a, int b)
{
    int s=0;
    while(a>0 || b>0){
        s+=abs((a%10)-(b%10));
        a/=10;
        b/=10;
    }
    return s;
}

int main()
{
    freopen("distance.inp","r",stdin);
    freopen("distance.out","w",stdout);
    int a,b;
    cin>>a>>b;
    cout<<d(a,b);
    return 0;
}
