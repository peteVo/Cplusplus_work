#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

bool notPrime[1001];
vector<ll> primes;
ll f[10001][1001] = {0};

void Sieve()
{
    ll m = sqrt(1000);
    notPrime[0] = true, notPrime[1] = true;
    for(ll i = 2; i <= m; ++i){
        if(!notPrime[i])
            for(ll j = i; j <= 1000/i; ++j)
                notPrime[i*j] = true;
    }

    for(ll i = 100; i <= 999; ++i)
        if(!notPrime[i]) primes.push_back(i);
}

ll Solve(ll n)
{
    ll k = 3;
    for(ll i = 0; i < primes.size(); ++i){
        f[k][primes[i]] = 1;
    }
    while(k < n){
        k++;
        for(ll i = 0; i < primes.size(); ++i){
            for(ll v = 1; v <= 9; v += 2){
                ll q = primes[i] % 100 * 10 + v;
                if(!notPrime[q])
                    f[k][primes[i]] = (f[k][primes[i]] + f[k-1][q]) % (ll)(1e9 + 9);
            }
        }
    }
    ll ans = 0;
    for(ll i = 0; i < primes.size(); ++i){
        ans = (ans + f[n][primes[i]]) % (ll)(1e9 + 9);
    }
    return ans % (ll)(1e9 + 9);
}

int main()
{
    freopen("prime3.inp", "r", stdin);
    freopen("prime3.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Sieve();
    ll n; cin >> n;
    cout << Solve(n);

    return 0;
}
