#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    freopen("pointset.inp", "r", stdin);
    freopen("pointset.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    map<ll, ll> m;
    ll n; cin >> n;
    ll x, y;
    for(int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        m[x+y]++;
    }

    ll ans = n;
    for(map<ll, ll>::iterator it = m.begin(); it != m.end(); ++it){
        ans -= it->second - 1;
    }
    cout << ans << "\n";

    return 0;
}
