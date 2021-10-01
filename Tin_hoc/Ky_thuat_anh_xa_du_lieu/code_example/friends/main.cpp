#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;

ll n, B;
map<ll, ll> a;

void ReadData()
{
    ll x;
    cin >> n >> B;
    for(ll i = 0; i < n; ++i){
        cin >> x;
        a[x]++;
    }
}

ll Friends()
{
    ll cnt = 0;
    for(map<ll, ll>::iterator it = a.begin(); it != a.end(); ++it){
        ll find = B - it->first;
        if(a.find(find) != a.end() && find > it->first) cnt = cnt + it->second * a[find];
        else if(find == it->first) cnt = cnt + it->first * (it->first - 1) / 2;
    }
    return cnt;
}

int main()
{
    freopen("friends.inp", "r", stdin);
    freopen("friends.out", "w", stdout);

    ReadData();
    cout << Friends();

    return 0;
}
