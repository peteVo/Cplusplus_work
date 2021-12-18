#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

ll check(pair<ll, ll> x, pair<ll, ll> y, pair<ll, ll> z, pair<ll, ll> t)
{
    if(x.second == y.second && y.first == z.first &&
       z.second == t.second && t.first == x.first &&
       y.first - x.first == y.second - z.second)
        return (y.first - x.first) *(y.first - x.first);
    else return -1;
}

ll CheckRect()
{
    pair<ll, ll> a[4];
    for(ll i = 0; i < 4; ++i){
        cin >> a[i].first >> a[i].second;
    }

    for(ll i = 0; i < 4; i++){
        for(ll j = 0; j < 4; j++){
            if(j == i) continue;
            for(ll k = 0; k < 4; k++){
                if(k == j || k == i) continue;
                for(ll l = 0; l < 4; ++l){
                    if(l == k || l == j || l == i) continue;
                    ll x = check(a[i], a[j], a[k], a[l]);
                    if(x > 0) return x;
                }
            }
        }
    }
    return -1;
    //check(a[1], a[2], a[3], a[0]);
}

int main()
{
    freopen("checkrect.inp", "r", stdin);
    freopen("checkrect.out", "w", stdout);

    cout << CheckRect();

    return 0;
}
