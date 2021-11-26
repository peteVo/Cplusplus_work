#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n;
pair<ll, ll> a[100001];
ll sa[100001] = {0}, sha[100001] = {0};

void ReadData()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].first;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].second;

    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        sa[i] = sa[i - 1] + a[i].second;
        sha[i] = sha[i - 1] + a[i].second * a[i].first;
    }
}

ll price(int index)
{
    ll ans = 0;
    ans += a[index].first * sa[index - 1] - sha[index - 1];            // Left part
    ans += sha[n] - sha[index] - a[index].first * (sa[n] - sa[index]); // Right part
    return ans;
}

void Solve()
{
    ll p = -1, energy = 1e13;
    for (int i = 1; i <= n; ++i)
    {
        ll tempEnergy = price(i);
        if (tempEnergy < energy)
        {
            p = a[i].first;
            energy = tempEnergy;
        }
        //cout << a[i].first << " " << tempEnergy << endl;
    }
    cout << p << " " << energy << endl;
}

int main()
{
    freopen("fly.inp", "r", stdin);
    freopen("fly.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
