#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n;
ll a[100001], b[100001];

void ReadData()
{
    // Read the input data
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
}

ll PointWin(ll target, ll x[])
{
    ll lo = 1, hi = n;
    ll ans = 0;
    while(lo <= hi){
        ll m = (lo + hi)/2;
        if(x[m] >= target){
            hi = m - 1;
        }
        else {
            ans = m;
            lo = m + 1;
        }
    }
    return 3 * ans;
}

ll lower(ll target, ll x[])
{
    ll lo = 1, hi = n;
    ll pos = -1;
    while(lo <= hi){
        ll m = (lo + hi)/2;
        if(x[m] >= target){
            if(x[m] == target) pos = m;
            hi = m - 1;
        }
        else lo = m + 1;
    }
    return pos;
}

ll upper(ll target, ll x[])
{
    ll lo = 1, hi = n;
    ll pos = -1;
    while(lo <= hi){
        ll m = (lo + hi)/2;
        if(x[m] <= target){
            if(x[m] == target) pos = m;
            lo = m + 1;
        }
        else hi = m - 1;
    }
    return pos;
}

ll PointDraw(ll target, ll x[])
{
    ll low = lower(target, x), upp = upper(target, x);
    if(low > 0 && upp > 0) return upp - low + 1;
    else return 0;
}

void Solve()
{
    ll p1 = 0, p2 = 0;
    for(int i = 1; i <= n; ++i){
        p1 = p1 + PointWin(a[i], b) + PointDraw(a[i], b);
        p2 = p2 + PointWin(b[i], a) + PointDraw(b[i], a);
    }
    cout << p1 << " " << p2 << endl;
}

int main()
{
    freopen("pigrace.inp", "r", stdin);
    freopen("pigrace.out", "w", stdout);

    ReadData();
    //cout << upper(2, b);
    Solve();

    return 0;
}
