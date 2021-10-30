#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll Solve(ll n, ll curpow)
{
    if (n == 1)
        return 0;
    if (n > curpow)
    {
        return 1 + Solve(n - curpow, curpow * 2);
    }
    else
        return 1 + Solve(n - 1, curpow);
}

int main()
{
    freopen("power.inp", "r", stdin);
    freopen("power.out", "w", stdout);

    ll n = 0;
    cin >> n;
    cout << Solve(n, 1);

    return 0;
}
