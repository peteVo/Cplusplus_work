#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll maxN = 1e6;
const ll MOD = 1e9 + 7;

bool notPrime[maxN+1] = {false};
ll freq[maxN+1] = {0};

ll logarithm(ll x, ll base)
{
    return log2(x) / log2(base);
}

void Sieve()
{
    notPrime[0] = true, notPrime[1] = true;
    ll m = sqrt(maxN);
    for(ll i = 2; i <= m; ++i){
        if(!notPrime[i]){
            for(ll j = i, len = maxN / i; j <= len; ++j){
                notPrime[i*j] = true;
            }
        }
    }
    //for(int i = 1; i <= 20; ++i){
    //    cout << i << " -> " << !notPrime[i] << endl;
    //}
}

ll Solve(ll n)
{
    ll ans = 1;
    for(ll i = 2; i <= n; ++i){
        if(!notPrime[i]){
            ll fre = logarithm(n, i);
            while(fre--)
                ans = ans * i % MOD;
        }
    }
    return ans;
}

int main()
{
    freopen("lcm.inp", "r", stdin);
    freopen("lcm.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Sieve();
    ll n; cin >> n;
    cout << Solve(n);

    return 0;
}
