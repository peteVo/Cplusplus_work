#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll Solve(ll n)
{
    if (n == 1)
        return 0;
    if (n % 2 == 0)
        return Solve(n / 2) + 1;
    return Solve(n - 1) + 1;
}

int main()
{
    freopen("power.inp", "r", stdin);
    freopen("power.out", "w", stdout);

    ll n = 0;
    cin >> n;
    cout << Solve(n);

    return 0;
}
