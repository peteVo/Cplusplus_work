#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll value(ll x, ll y)
{
    ll ans = 1;
    ll i;
    for(i = 1; i < x; ++i){
        ans += i;
    }
    for(ll j = 1; j < y; ++j){
        ans += i + j;
    }
    return ans;
}

pair<ll, ll> coords(ll z)
{
    ll i;
    for(i = 1; i <= 1e9; ++i){
        if(z > i) z -= i;
        else break;
    }
    pair<ll, ll> ans;
    ans = pair<ll, ll>(i - z + 1, z);
    return ans;
}

int main()
{
    freopen("mapping.inp", "r", stdin);
    freopen("mapping.out", "w", stdout);

    ll x, y, z;
    cin >> x >> y >> z;
    cout << value(x, y) << endl;
    pair<ll, ll> ans = coords(z);
    cout << ans.first << " " << ans.second;

    return 0;
}
