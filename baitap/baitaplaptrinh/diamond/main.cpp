#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll n, m;
ll a[502][502] = {0}, s[502][502] = {0};

void ReadData()
{
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j){
            cin >> a[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
    }
}

ll sum_diamond(ll x, ll y, ll k)
{
    ll cnt = 0;
    for(int i = x - k + 1; i <= x + k - 1; ++i){
        ll dif_x = abs(i - x);
        cnt = cnt + s[i][y + k - dif_x - 1] - s[i][y - k + dif_x] - s[i - 1][y + k - dif_x - 1] + s[i - 1][y - k + dif_x];
    }
    return cnt;
}

int Solve()
{
    ll ans = 0;
    ll max_k = (min(n, m) + 1) / 2;
    for(ll k = 1; k <= max_k; ++k){
        for(ll i = k; i <= n - k + 1; ++i){
            for(ll j = k; j <= m - k + 1; ++j){
                ans = max(ans, sum_diamond(i, j, k));
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("diamond.inp", "r", stdin);
    freopen("diamond.out", "w", stdout);

    ReadData();
    cout << Solve();
    //sum_diamond(3, 2, 2);

    return 0;
}
