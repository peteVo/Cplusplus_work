#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

ll Position(ll n)
{
    ll m=n, pos=0,i=1,multiplyer=1;
    while(n>=10){
        pos+=9*i*multiplyer;
        i++;
        multiplyer*=10;
        n/=10;
    }
    pos+=(m-multiplyer+1)*i;
    return pos;
}

int main()
{
    freopen("seqlen.inp","r",stdin);
    freopen("seqlen.out","w",stdout);
    ll n;
    cin>>n;
    cout<<Position(n);
    return 0;
}
