#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int maxMoney(int a,int b,int c)
{
    int H=0,L=0,money=0;
    for(H=0;H*a<=c;++H){
        L=(c-H*a)/b;
        if((H*a+L*b)>money){
            money=H*a+L*b;
        }
    }
    return money;
}

int main()
{
    freopen("flowers.inp","r",stdin);
    freopen("flowers.out","w",stdout);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<maxMoney(a,b,c);
    return 0;
}
