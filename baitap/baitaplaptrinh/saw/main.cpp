#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

int n, k;
ll maxH = -1;
ll h[100001], m[100001];

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
}

ll wood(ll height)
{
    ll cnt = 0;
    for(int i = 1; i <= n; ++i){
        cnt = cnt + max(height, h[i]) - height;
    }
    return cnt;
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

    return 0;
}
