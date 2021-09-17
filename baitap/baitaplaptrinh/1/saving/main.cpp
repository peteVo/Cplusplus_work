#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

long long numYears(double a,double r,double b)
{
     long long cnt=0;
     r/=100;
     while(a<b){
        a=a+a*r;
        r+=0.005;
        ++cnt;
     }
     return cnt;
}

int main()
{
    freopen("saving.inp","r",stdin);
    freopen("saving.out","w",stdout);
    double a,r,b;
    cin>>a>>r>>b;
    cout<<numYears(a,r,b);
    return 0;
}
