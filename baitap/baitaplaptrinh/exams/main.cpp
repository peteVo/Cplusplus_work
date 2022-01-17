#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, T, a[20], b[20];
ll m1, m2, lenx, leny;
ll x[300001], y[300001];

void ReadData()
{
    cin >> n >> T; m1 = n / 2, m2 = n - m1, lenx = 1 << m1, leny = 1 << m2;
    for(ll i = 1; i <= m1; ++i) cin >> a[i];
    for(ll i = 1; i <= m2; ++i) cin >> b[i];
}

ll GetBit(ll t, ll k)
{
    return (t >> k) & 1;
}

ll GetSum(ll t, ll arr[], ll len)
{
    ll s = 0;
    for(ll k = 0; k < n; ++k){
        if(GetBit(t, k) == 1) s = s + arr[k+1];
    }
    return s;
}

ll BinSearch(ll num)
{
    ll pos = -1;
    ll lo = 0, hi = leny - 1;
    while(lo <= hi){
        ll m = (lo + hi) / 2;
        if(y[m] >= num) hi = m - 1, pos = m;
        else lo = m + 1;
    }
    return pos;
}

ll Solve()
{
    for(int it = 0; it < lenx; ++it){
        x[it] = GetSum(it, a, m1);
    }
    for(int it = 0; it < leny; ++it){
        y[it] = GetSum(it, b, m2);
    }
    sort(x, x + lenx); sort(y, y + leny);

    ll ans = 0;
    for(int i = 0; i < lenx; ++i){
        ll num = x[i];
        ll pos = BinSearch(T - num);
        if(pos == -1) continue;
        ans = ans + leny - pos;
    }
    //for(int i = 0; i < lenx; ++i) cout << y[i] << " ";

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("exams.inp", "r", stdin);
    freopen("exams.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
