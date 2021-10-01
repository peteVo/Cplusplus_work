#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
map<ll, pii> s;
ll n;
ll a[100001];

void ReadData()
{
    cin >> n;
    ll sum = 0;
    s[sum] = pii(0, 0);
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
        if(s.find(sum) != s.end()){
            s[sum] = pii(min(s[sum].first, i), max(s[sum].second, i));
        }
        else s[sum] = pii(i, i);
    }
}

void Solve()
{
    ll lo, hi;
    ll maxLen = -1;
    for(map<ll, pii>::iterator it = s.begin(); it != s.end(); ++it){
        if(it->second.second - it->second.first > maxLen){
            maxLen = it->second.second - it->second.first;
            lo = it->second.first + 1;
            hi = it->second.second;
        }
    }
    cout << lo << " " << hi;
}

int main()
{
    freopen("szero.inp", "r", stdin);
    freopen("szero.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
