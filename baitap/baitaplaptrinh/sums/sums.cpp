#include <iostream>
#include <cstdio>
#include <cmath>

typedef long long ll;
using namespace std;

void Solve(ll n)
{
    for(ll l = 2; l*(l+1)/2 <= n; ++l){
        double a = (n - l*(l-1.0)/2.0) / l;
        if(a > 0 && floor(a) == ceil(a)){
            cout << n << " = ";
            for(ll i = 0; i < l; ++i){
                cout << (ll)a + i;
                if(i < l - 1) cout << " + ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("sums.inp", "r", stdin);
    freopen("sums.out", "w", stdout);

    ll t; cin >> t;
    for(ll i = 0; i < t; ++i){
        ll x; cin >> x; Solve(x);
    }

    return 0;
}
