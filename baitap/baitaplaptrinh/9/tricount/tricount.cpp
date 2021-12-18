#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
typedef long long ll;
map<ll, ll> Ox, Oy;
int n;
pair<ll, ll> a[300001];

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
        Ox[a[i].first]++;
        Oy[a[i].second]++;
    }
}

ll Solve()
{
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = ans + (Ox[a[i].first] - 1) * (Oy[a[i].second] - 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("tricount.inp", "r", stdin);
    freopen("tricount.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
