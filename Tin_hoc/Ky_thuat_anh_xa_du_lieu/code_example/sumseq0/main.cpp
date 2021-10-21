#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
typedef long long ll;
typedef map<ll, ll> _map;
_map s;
int n;

ll ReadData()
{
    ll cnt = 0;
    cin >> n;
    s[0] = 1;
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        ll x;
        cin >> x;
        sum += x;
        s[sum]++;
        cnt += s[sum] - 1;
    }
    return cnt;
}

int main()
{
    freopen("sumseq0.inp", "r", stdin);
    freopen("sumseq0.out", "w", stdout);

    cout << ReadData();

    return 0;
}
