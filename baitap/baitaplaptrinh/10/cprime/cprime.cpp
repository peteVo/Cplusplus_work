#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;
const ll maxN = 1000000;

ll d[maxN + 1] = {0};
ll divs[maxN + 1] = {0};
ll s[maxN + 1] = {0};
ll cntpr[maxN + 1] = {0}, cntsqr[maxN + 1] = {0};

void Sieve()
{
    d[0] = 1, d[1] = 1;
    ll m = sqrt(maxN);
    for(ll i = 2; i <= m; ++i){
        if(d[i] == 0){
            for(ll j = i; i*j <= maxN; ++j){
                d[i*j] = i;
            }
        }
    }

    for(int x = 1; x <= m; ++x){
        divs[x*x]++;
        for(int y = x + 1, len = maxN/x; y <= len; ++y){
            divs[x*y] += 2;
        }
    }
}

ll CountDiv(ll n)
{
    map<ll, ll> r;
    while(n > 1){
        ll p = d[n];
        if(p == 0) p = n;
        r[p]++;
        n /= p;
    }
    ll ans = 1;
    for(map<ll, ll>::iterator it = r.begin(); it != r.end(); it++){
        ans *= 2*it->second + 1;
    }
    return ans;
}

void Prep()
{
    for(int i = 1; i <= maxN; ++i){
        if(d[divs[i]] == 0) s[i] = s[i-1] + 1;
        else s[i] = s[i-1];
    }

    for(int i = 1; i <= maxN; ++i){
        cntpr[i] = cntpr[i-1], cntsqr[i] = cntsqr[i-1];
        ll x = CountDiv(i);
        if(x > 2 && d[x] == 0) cntsqr[i]++;
        if(d[i] == 0) cntpr[i]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("cprime.inp", "r", stdin);
    freopen("cprime.out", "w", stdout);

    Sieve();
    Prep();

    ll T; cin >> T;
    for(int i = 0; i < T; ++i){
        ll a, b; cin >> a >> b;
        if(b <= maxN){
            cout << s[b] - s[a-1] << "\n";
        }
        else{
            ll aa = sqrt(a-1), bb = sqrt(b);
            ll ans = cntsqr[bb] - cntsqr[aa];
            cout << ans << "\n";
        }
    }

    return 0;
}

