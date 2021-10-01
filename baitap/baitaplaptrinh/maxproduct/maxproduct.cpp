#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

pii a[200001];
int n;
ll T;

bool sorter(pii x, pii y)
{
    return (x.first < y.first ||
            (x.first == y.first && x.second < y.second));
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

bool notOverflow(ll x, ll y)
{
    ll product = x * y;
    return product >= x && product >= y;
}

bool isValid(ll x, ll y)
{
    return x * y <= T;
}

int BinarySearch(ll x, int lo, int hi)
{
    int pos = -1;
    while(lo <= hi)
    {
        int m = (lo + hi) / 2;
        if(notOverflow(x, a[m].first && isValid(x, a[m].first))){
            pos = m;
            lo = m + 1;
            if(a[m].first * x == T) return m;
        }
        else hi = m - 1;
    }
    return pos;
}

void Solve()
{
    ll maxVal = -1;
    ll pos1 = -1, pos2 = -1;
    for(int i = 1; i <= n; ++i){
        int pos = BinarySearch(a[i].first, i+1, n);
        if(pos == -1) continue;
        if(a[i].first * a[pos].first > maxVal){
            maxVal = a[i].first * a[pos].first;
            pos1 = a[i].second;
            pos2 = a[pos].second;
        }
    }
    cout << maxVal << endl;
    cout << pos1 << " " << pos2 << endl;
}

int main()
{
    freopen("maxproduct.inp", "r", stdin);
    freopen("maxproduct.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
