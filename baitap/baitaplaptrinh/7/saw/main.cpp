#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, k;
ll maxH = -1;
ll h[100001], m[100001];
ll s[100001] = {0};

void ReadData()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> h[i];
        maxH = max(maxH, h[i]);
    }
    for(int i = 1; i <= k; ++i){
        cin >> m[i];
    }
    sort(h + 1, h + 1 + n);
    for(int i = 1; i <= n; ++i){
        s[i] = s[i-1] + h[i];
    }
}

ll wood(ll height)
{
    ll pos = -1;
    ll lo = 1, hi = n;
    while(lo <= hi){
        ll m = (lo + hi) / 2;
        if(h[m] >= height){
            pos = m;
            hi = m - 1;
        }
        else lo = m + 1;
    }

    //cout << "pos = " << pos << endl;
    return s[n] - s[pos-1] - height * (n - pos + 1);
}

ll BinarySearch(ll minWood)
{
    ll w, m;
    ll ans = -1;
    ll lo = 0, hi = maxH;
    while(lo <= hi){
        m = (lo + hi) / 2;
        w = wood(m);
        if(w >= minWood){
            ans = m;
            lo = m + 1;
        }
        else hi = m - 1;
    }
    ///////DEBUG////////
    //cout << endl << "Height of: " << ans << " ----> wood(out): " << wood(ans) << " ----> minWood: " << minWood << endl;
    return ans;
}

void Solve()
{
    for(int i = 1; i <= k; ++i){
        cout << BinarySearch(m[i]) << " ";
    }
    cout << endl;
}

int main()
{
    freopen("saw.inp", "r", stdin);
    freopen("saw.out", "w", stdout);

    ReadData();
    Solve();
    //cout << wood(10);

    return 0;
}
