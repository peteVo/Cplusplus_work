#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int atm(int a,int b,int c,int n)
{
    int s=0,x,y,z;
    for(y=0;y<=min(b,n/10);++y){
        for(z=0;z<=min(c,n/20);++z){
            x=(n-10*y-20*z)/5;
            if(x<=min(a,n/5) && x>=0 && 5*x+10*y+20*z==n) s++;
        }
    }
    return s;
}
int main()
{
    freopen("atm.inp","r",stdin);
    freopen("atm.out","w",stdout);
    int a, b ,c, n;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>n;
    cout<<atm(a,b,c,n);
    return 0;
}
