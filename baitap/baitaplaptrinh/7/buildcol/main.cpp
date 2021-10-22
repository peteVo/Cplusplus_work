#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;
ll n, M;
ll a[100001];
ll maxA = 0;
ll leftMax[100001], rightMax[100001];

ll Water(ll X)
{
    ll cnt = 0;
    for(int i = 2; i < n; ++i){
        cnt = cnt + max(min(leftMax[i], rightMax[i]) - max(a[i], X), (ll)0); // can be negative
    }
    return cnt;
}

void ReadData()
{
    cin >> n >> M;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        maxA = max(maxA, a[i]);
    }
    ll _max = 0;
    for(int i = 1; i <= n; ++i){
        _max = max(_max, a[i]);
        leftMax[i] = _max;
    }
    _max = 0;
    for(int i = n; i >= 1; --i){
        _max = max(_max, a[i]);
        rightMax[i] = _max;
    }
}

ll HeighestLevel()
{
    ll lo = 1, hi = maxA;
    ll ans = -1;
    while(lo <= hi){
        ll m = (lo+hi)/2;
        if(Water(m) >= M){
            ans = m;
            lo = m + 1;
        }
        else hi = m - 1;
    }
    return ans;
}

int main()
{
    freopen("buildcol.inp", "r", stdin);
    freopen("buildcol.out", "w", stdout);

    ReadData();
    cout << HeighestLevel();
    //for(int i = 1; i <= 6; ++i) cout << endl << "Water(" << i << "): " << Water(i);

    return 0;
}
