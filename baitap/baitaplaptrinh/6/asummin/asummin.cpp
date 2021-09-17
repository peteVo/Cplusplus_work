#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
ll m, n, a[100001], b[100001], copA[100001], copB[100001];

void ReturnValue(ll i, ll j);
ll MinIndexB(ll indexA);

void ReadData()
{
    cin >> m >> n;
    for(ll i = 1; i <= m; ++i){
        cin >> a[i];
        copA[i] = a[i];
    }
    for(ll i = 1; i <= n; i++){
        cin >> b[i];
        copB[i] = b[i];
    }

    sort(a + 1, a + 1 + m);
    sort(b + 1, b + 1 + n);
    //for(ll i = 1; i <= m; ++i) cout<<a[i]<<endl;
    //for(ll i = 1; i <= n; ++i) cout<<b[i]<<endl;
}

void SUMMIN()
{
    ll minA, minB, minValue = 1e10;

    for(int i = 1; i <= m; ++i){
        ll j = MinIndexB(i);

        ll ABS = abs(b[j] + a[i]);
        if(minValue > ABS){
            minValue = ABS;
            minA = i;
            minB = j;
        }
    }
    ReturnValue(minA, minB);
    return;
}

ll MinIndexB(ll indexA)
{
    ll x = -a[indexA];
    ll lo = 1, hi = n;

    while(lo <= hi){
        ll mid = (lo + hi)/2;
        if(b[mid] <= x){
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    if(lo <= 1) return lo;
    if(lo - 1 >= n) return lo-1;
    if(abs(b[lo]-x) < abs(b[lo - 1] - x)){
        return lo;
    }
    return lo - 1;
}

void ReturnValue(ll minA, ll minB)
{
    ll x = a[minA];
    ll y = b[minB];

    for(ll i = 1; i <= m; ++i){
        if(copA[i] == x){
            cout << i << " ";
            break;
        }
    }

    for(ll i = 1; i <= n; ++i){
        if(copB[i] == y){
            cout << i << endl;
            break;
        }
    }
    return;
}

int main()
{
    freopen("asummin.inp", "r", stdin);
    freopen("asummin.out", "w", stdout);

    ReadData();
    SUMMIN();

    return 0;
}
