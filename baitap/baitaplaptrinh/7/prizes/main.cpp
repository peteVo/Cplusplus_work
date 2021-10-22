#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
ll n, k;
ll a[100001];
ll s[100001] = {0};
ll l[100001] = {0};
ll r[100001] = {0};

void ReadData()
{
    cin >> n >> k;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
}

ll Solve()
{
    ll subans = -1, ans = 1e18;
    for(ll i = k; i <= n; ++i){
        l[i] = max(l[i-1], s[i] - s[i-k]);
        //cout << "l[" << i << "] = " << l[i] << endl;
    }
    for(ll i = n-k+1; i >= 1; --i){
        r[i] = max(r[i+1], s[i+k-1] - s[i-1]);
        //cout << "r[" << i << "] = " << r[i] << endl;
    }
    for(ll i = 1; i <= n-k+1; ++i){
        //cout << "max(l[" << i << "], r[" << i << "]) = " << max(l[i], r[i]) << endl;
        subans = max(l[i-1], r[i+k]);
        ans = min(ans, subans);
    }
    return ans;
}

int main()
{
    freopen("prizes.inp", "r", stdin);
    freopen("prizes.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
