#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll Solve(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        ans++;
        n /= 2;
    }
    return ans;
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
