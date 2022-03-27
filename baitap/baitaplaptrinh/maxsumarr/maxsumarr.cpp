#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll MIN_LL = -9223372036854775808;

ll n;
ll a[100001];
ll rev_s[100001];

void ReadData()
{
    rev_s[0] = 0;
    cin >> n;
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(ll i = 1; i <= n; ++i)
        rev_s[i] = rev_s[i-1] - a[i];
}

ll Solve()
{
    ll ans = -MIN_LL;
    for(ll i = 1; i <= n; ++i)
    {
        ans = max(ans, a[i] * (n - i + 1) + rev_s[i-1]);
        ll k = a[i] * (n - i + 1);
        ll j = rev_s[i-1];
        ll g = 0;
    }
    return ans;
}

int main()
{
    freopen("maxsumarr.inp", "r", stdin);
    freopen("maxsumarr.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ReadData();
        cout << Solve() << "\n";
    }

    return 0;
}
