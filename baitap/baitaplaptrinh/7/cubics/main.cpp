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
    ll pos = 1e9;
    ll maxLen = -1;
    for(map<ll, pii>::iterator it = s.begin(); it != s.end(); ++it){
        ll dif = it->second.second - it->second.first;
        ll firstpos = it->second.first + 1;
        if(dif > maxLen){
            pos = 1e9;
            maxLen = dif;
            pos = firstpos;
        }
        else if(dif == maxLen && pos > firstpos){
            pos = firstpos;
        }
    }
    if(maxLen > -1)
        cout << maxLen << " " << pos;
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
