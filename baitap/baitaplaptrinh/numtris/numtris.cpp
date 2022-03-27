#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll power3(ll n, ll p)
{
    if(p == 1)
        return 3 % MOD;

    ll a = power3(a, p / 2);
    a = a*a % MOD;
    if(p & 1)
        return a * 3 % MOD;
    return a % MOD;
}

// a[n] = 2*3^n - 1
ll Solve(ll n)
{
    return (power3(1, n) * 2 - 1) % MOD;
}

int main()
{
    freopen("numtris.inp", "r", stdin);
    freopen("numtris.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t, n; cin >> t;
    while(t--)
    {
        cin >> n;
        cout << Solve(n) << "\n";
    }

    //cout << power3(1, 5);
    return 0;
}
