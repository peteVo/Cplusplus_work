#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll n;
ll h[100001], a[100001];
map<ll, pii> m;

void ReadData()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

void Solve()
{
    for (int i = 1; i <= n; ++i)
    {
        if (m.find(h[i]) != m.end())
        {
            m[h[i]].second += a[i];
        }
        else
            m[h[i]] = pii(h[i], a[i]);
    }

    ll maxfreq = 0;
    ll p = 0;
    ll energy = 0;
    for (map<ll, pii>::iterator it = m.begin(); it != m.end(); ++it)
    {
        if (it->second.second > maxfreq)
        {
            p = it->second.first;
            maxfreq = it->second.second;
        }
    }
    for (map<ll, pii>::iterator it = m.begin(); it != m.end(); ++it)
    {
        if (it->second.first != p)
        {
            energy = energy + abs(p - it->second.first) * it->second.second;
        }
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
