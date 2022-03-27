#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;

ll n, m;
ll c[51] = {0};
ll f[51][251] = {0};
ll ans = 0;

void ReadData()
{
    cin >> n >> m;
    for(ll i = 1; i <= m; ++i) cin >> c[i];
}

void Prep()
{
    for(ll i = 0; i <= m; ++i) f[i][0] = 1;
    for(ll x = 1; x <= m; ++x){
        for(ll y = 1; y <= n; ++y){
            for(ll k = 0, len = y / c[x]; k <= len; ++k){
                f[x][y] += f[x-1][y - k*c[x]];
            }
        }
    }
    /*
    for(ll x = 1; x <= m; ++x){
        for(ll y = 1; y <= n; ++y){
            cout << f[x][y] << " ";
        }
        cout << endl;
    }
    */
    return;
}

int main()
{
    freopen("coinchange.inp", "r", stdin);
    freopen("coinchange.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ReadData();
    Prep();
    cout << f[m][n];

    return 0;
}
