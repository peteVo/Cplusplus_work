/*
ll TotalLines(ll x)
{
    ll linesA = 1, linesB = 1;
    //Find lines of A
    ll temp = x;
    for(ll i = 1; i <= n; ++i){
        if(x < a[i]) return -1;
        if(temp >= a[i]){
            temp -= a[i];
        }
        else{
            temp = x - a[i];
            linesA++;
        }
    }

    //Find lines of B
    ll y = w-x;
    temp = y;
    for(ll i = 1; i <= m; ++i){
        if(y < b[i]) return -1;
        if(temp >= b[i]){
            temp -= b[i];
        }
        else{
            temp = y - b[i];
            linesB++;
        }
    }
    cout << linesA << " " << linesB;
}
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

//variables
ll w, n, m;
ll a[100001],b[100001];

void ReadData()
{
    cin >> w >> n >> m;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(ll i = 1; i <= m; ++i){
        cin >> b[i];
    }
}

ll Lines(ll arr[], int s, ll x)
{
    ll lines = 1;
    ll w = 0;
    for(ll i = 1; i <= s; ++i){
        if(x < arr[i])
            return 1e10;

        if(w + arr[i] <= x){
            w = w + arr[i] + 1;
        }
        else{
            w = arr[i] + 1;
            lines++;
        }
    }
    return lines;
}

ll MinLines()
{
    ll minLines = 1e10;
    ll lo = 1, hi = w - 1;
    while(lo <= hi){
        ll w1 = (lo+hi)/2;
        ll w2 = w - w1;
        ll l1 = Lines(a, n, w1);
        ll l2 = Lines(b, m, w2);
        minLines = min(minLines, max(l1, l2));
        if(l1 < l2){
            hi = w1-1;
        }
        else lo = w1+1;
    }
    return minLines;
}

int main()
{
    freopen("report.inp", "r", stdin);
    freopen("report.out", "w", stdout);

    ReadData();
    cout << MinLines();

    return 0;
}
