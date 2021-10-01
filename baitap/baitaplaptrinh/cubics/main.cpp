#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
ll n, k;
ll a;
typedef pair<ll, ll> pii;
map<ll, pii> s;
ll m[100001] = {0};

void ReadData()
{
    cin >> n >> k;
    ll sum = 0;
    s[sum] = pii(0, 0);
    for(ll i = 1; i <= n; ++i){
        m[i] = 1e6;
        cin >> a;
        a -= k;
        sum += a;
        if(s.find(sum) != s.end()){
            s[sum].second = i;
        }
        else s[sum] = pii(i, i);
    }
}

void Cubics()
{
    ll maxLen = -1;
    for(map<ll, pii>::iterator it = s.begin(); it != s.end(); ++it){
        if(it->second.second - it->second.first > maxLen){
            maxLen = it->second.second - it->second.first;
            m[maxLen] = min(m[maxLen], it->second.first + 1);
        }
    }
    if(maxLen >= 0)
        cout << maxLen << " " << m[maxLen];
    else cout << 0;
}

int main()
{
    freopen("cubics.inp", "r", stdin);
    freopen("cubics.out", "w", stdout);

    ReadData();
    Cubics();

    return 0;
}
