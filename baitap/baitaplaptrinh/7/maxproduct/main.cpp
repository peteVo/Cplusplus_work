#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
//#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
//map<ll, pii> a;

pii a[200001];
ll n, T;

bool sorter(pii x, pii y)
{
    return x.first < y.first || (x.first == y.first && x.second < y.second);
}

void ReadData()
{
    cin >> n >> T;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n, sorter);
}

ll BinarySearch(ll x, ll lo, ll hi)
{
    ll pos = -1;
    while(lo <= hi)
    {
        ll m = (lo + hi) / 2;
        if(a[m].first <= x){
            pos = m;
            lo = m + 1;
        }
        else hi = m - 1;
    }  
    return pos;  
}

void Solve()
{
    ll ans = -1;
    ll pos1 = -1, pos2 = -1;
    for(int i = 1; i <= n; ++i){
        ll pos = BinarySearch(T / a[i].first, i + 1, n);
        if(pos > 0 && ans < a[pos].first * a[i].first){
            ans = a[pos].first * a[i].first;
            pos1 = a[i].second, pos2 = a[pos].second;
        }
    }
    if(ans == -1 && pos1 == -1 && pos2 == -1) cout << 0;
    else{
        cout << ans << endl;
        cout << pos2 << " " << pos1 << endl; 
    }
}

int main()
{
    freopen("maxproduct.inp", "r", stdin);
    freopen("maxproduct.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
