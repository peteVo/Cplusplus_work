#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#define maxN 1e18

using namespace std;
typedef long long ll;
vector<pair<ll, ll> > ans;

ll capA[60] = {0};

void MakeCapA()
{
    capA[2] = 1e9, capA[3] = 1e6;
    for(ll i = 4; i <= 59; ++i){
        capA[i] = pow(maxN, (double)1 / i) + 1;
    }
}

ll power(ll x, ll y)
{
    ll res = 1;
    for(ll i = 0; i < y; ++i){
        res *= x;
    }
    return res;
}

void BinarySearch(ll b, ll x)
{
    ll lo = 2, hi = capA[b];
    while(lo <= hi){
        ll m = (lo + hi) / 2;
        ll p = power(m, b);
        if(p > x){
            hi = m - 1;
        }
        else if(p == x){
            ans.push_back(pair<ll, ll>(m, b));
            hi = m - 1;
        }
        else{
            lo = m + 1;
        }
    }
}

void Solve(ll x)
{
    ll log2x = log2(x);
    for(ll i = 2; i <= log2x; ++i){
        BinarySearch(i, x);
    }
}

int main()
{
    freopen("power.inp", "r", stdin);
    freopen("power.out", "w", stdout);

    MakeCapA();

    ll x;
    cin >> x;
    Solve(x);

    cout << ans.size() << endl;
    for(ll i = 0, len = ans.size(); i < len; ++i) cout << ans[i].first << " " << ans[i].second << endl;

    return 0;
}
