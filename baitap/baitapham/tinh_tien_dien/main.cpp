#include <iostream>
#include <cmath>
#include <cstdio>

typedef long long ll;
using namespace std;

ll bill(int n)
{
    ll s=0;
    s+=(ll)min(n,50)*14;
    n-=50;
    if(n>0){
        s=s+(ll)min(n,50)*15;
        n-=50;
    }
    if(n>0){
        s=s+(ll)min(n,100)*16;
        n-=100;
    }
    if(n>0){
        s=s+(ll)min(n,100)*17;
        n-=100;
    }
    if(n>0){
        s=s+(ll)min(n,100)*18;
        n-=100;
    }
    if(n>0) s=s+(ll)n*20;
    return s;
}

int main()
{
    freopen("bill.inp","r",stdin);
    freopen("bill.out","w",stdout);
    int n;
    cin>>n;
    cout<<bill(n);
    return 0;
}
