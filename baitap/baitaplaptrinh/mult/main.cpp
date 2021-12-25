#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

ll base_trans(ll n, ll base)
{
    ll ans = 0;
    ll mul = 1;
    while(n > 0){
        ll rem = n % base;
        if(rem > 9) return -1;
        ans = ans + rem * mul;
        mul *= 10, n /= base;
    }
    return ans;
}

void Solve()
{
    ll p, q, r; cin >> p >> q >> r;
    ll x = r;
    ll min_base = 2;
    while(x > 0){
        min_base = max(min_base, x % 10 + 1);
        x /= 10;
    }

    for(ll base = min_base; base <= 16; ++base){
        ll num = base_trans(p * q, base);
        if(num == r){
            cout << base << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mult.inp", "r", stdin);
    freopen("mult.out", "w", stdout);

    Solve();

    return 0;
}
