#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

ll PartialSolve(ll row, ll h)
{
    if (h == 1)
        return 1;
    if (row <= h / 2)
        return PartialSolve(row, h / 2);
    return PartialSolve(row - h / 2, h / 2) * 2;
}

ll Solve(ll n)
{
    ll i = 1;
    while (n > i)
    {
        n -= i;
        i *= 2;
    }
    return PartialSolve(n, i);
}

int main()
{
    freopen("light.inp", "r", stdin);
    freopen("light.out", "w", stdout);

    ll n;
    cin >> n;
    cout << Solve(n);

    //for(int i = 1; i <= 20; ++i) cout << Solve(i) << endl;
    return 0;
}
