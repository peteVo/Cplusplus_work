#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

ll n;
ll a[100];
ll f[100][100] = {0};
ll s[100] = {0};

void ReadData()
{
    cin >> n;
    for(unsigned i = 0; i < n; i++) cin >> a[i];
    s[0] = a[0];
    for(unsigned i = 1; i < n; i++) s[i] = s[i-1] + a[i];
}

ll color(ll i, ll j)
{
    return (s[j] - s[i-1]) % 100;
}

ll Solve()
{
    for(unsigned i = 0; i < n; ++i){
        for(unsigned j = i + 1; j < n; ++j){
            ll minval = 1e18;
            for(ll k = i; k < j; ++k){
                minval = min(minval, f[i][k] + f[k+1][j] + color(i, k) * color(k+1, j));
            }
            f[i][j] = minval;
        }
    }
    return f[0][n-1];
}

int main()
{
    freopen("mixtures.inp", "r", stdin);
    freopen("mixtures.out", "w", stdout);

    ll T;
    cin >> T;
    for(ll i = 0; i < T; ++i){
        ReadData();
        cout << Solve() << endl;
    }

    return 0;
}
