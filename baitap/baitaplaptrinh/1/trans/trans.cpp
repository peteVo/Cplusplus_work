#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;

void minMoney(ll n,ll a, ll b)
{
    ll bus=n/50, taxi;
    if(a*2>=b*25){
        cout<<0<<" "<<(n+3)/4;
    }
    else{
        if(a<b*((n%50+3)/4)) bus++;
        else taxi=(n%50+3)/4;
        cout<<bus<<" "<<taxi;
    }
}

int main()
{
    freopen("trans.inp","r",stdin);
    freopen("trans.out","w",stdout);
    ll n,a,b;
    cin>>n>>a>>b;
    minMoney(n,a,b);
    return 0;
}
