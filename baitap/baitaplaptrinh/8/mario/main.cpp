#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;
ll n;
ll h[1000001] = {0};

void ReadData()
{
    cin >> n;
    for(ll i = 1; i <= n; ++i){
        cin >> h[i];
    }
}

bool isOverflow(ll x)
{
    if(x > 0){
        return 2*x <= x;
    }
    if(x < 0){
        return 2*x >= x;
    }
    else return 2*x/2 == x;
}

bool isValid(ll x)
{
    for(ll i = 1; i <= n; ++i){
        if(isOverflow(x)) return true;
        x = 2*x - h[i];
        if(x < 0) return false;
        //cout << x << " ";
    }
    return true;
}

ll minK()
{
    ll ans = -1;
    ll lo = 1, hi = 1e18;
    while(lo <= hi){
        ll m = (lo + hi) / 2;
        if(isValid(m)){
            hi = m - 1;
            ans = m;
        }
        else lo = m + 1;
    }
    return ans;
}

int main()
{
    freopen("mario.inp", "r", stdin);
    freopen("mario.out", "w", stdout);

    ReadData();
    cout << minK();

    return 0;
}
