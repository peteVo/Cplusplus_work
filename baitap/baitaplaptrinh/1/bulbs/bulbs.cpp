#include <iostream>
#include <cmath>
#include <cstdio>

int soUoc(int x)
{
    int cnt=0, m=sqrt(x);
    for(int i=1;i<=m;++i){
        if(x%i==0) ++cnt;
    }
    if(m*m==x) cnt=2*cnt-1;
    else cnt*=2;
    return cnt;
}

using namespace std;

bool bulbN(int n)
{
    bool state;
    if(soUoc(n)%2==0) return false;
    else return true;
}

int main()
{
    freopen("bulbs.inp","r",stdin);
    freopen("bulbs.out","w",stdout);
    int n;
    cin>>n;
    if(bulbN(n)) cout<<"ON";
    else cout<<"OFF";
    return 0;
}
