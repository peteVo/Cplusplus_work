#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

ll n;
ll x;
map<ll, ll> a;

void ReadData()
{
    cin >> n;
    ll temp;
    for(ll i = 1; i <= n; ++i){
        cin >> temp;
        if(a.find(temp) != a.end())
            a[temp]++;
        else a[temp] = 1;
    }
    cin >> x;
}

ll Solve()
{
    ll cnt = 0;
    for(map<ll, ll>::iterator it = a.begin(); it != a.end(); ++it){
        if(x - it->first > it->first && a.find(x - it->first) != a.end()) cnt = cnt + it->second * a[x - it->first];
        else if (x - it->first == it->first) cnt = cnt + it->second * (it->second - 1) / 2;
    }
    return cnt;
}

int main()
{
    freopen("sumx.inp","r",stdin);
    freopen("sumx.out","w",stdout);
    ReadData();
    cout << Solve();
    return 0;
}
