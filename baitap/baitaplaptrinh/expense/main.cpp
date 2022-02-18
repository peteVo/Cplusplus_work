#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll n, m;
ll c[2001];
ll f[2001][2001];

void ReadData()
{
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) cin >> c[i];
}

void Prep()
{
    for(ll x = 0; x <= n; ++x)
        for(ll y = 0; y <= m; ++y)
            f[x][y] = 0;
    for(ll i = 0; i <= n; ++i) f[i][0] = 1;

    for(ll x = 1; x <= n; ++x){
        for(ll y = 1; y <= m; ++y){
            for(ll k = 0, len = y / c[x]; k <= len; ++k){
                f[x][y] += f[x-1][y - k * c[x]];
            }
        }
    }
    return;
}

void Solve()
{
    for(ll y = m; y >= 0; --y){
        if(f[n][y] > 0){
            cout << y << "\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("expense.inp", "r", stdin);
    freopen("expense.out", "w", stdout);

    ll t; cin >> t;
    for(ll i = 0; i < t; ++i){
        ReadData();
        //cout << n << " " << m << endl;
        Prep();
        Solve();
    }

    return 0;
}
