#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

const ll maxN = 1000000;
bool notPrime[1000001] = {false};
vector<ll> primes;
ll len_primes;

void Sieve()
{
    notPrime[0] = true, notPrime[1] = true;
    ll m = sqrt(maxN);
    for(ll i = 2; i <= m; ++i){
        if(!notPrime[i])
            for(ll j = i, len = maxN / i; j <= len; ++j)
                notPrime[i*j] = true;
    }
    for(ll i = 1; i <= maxN; ++i) if(!notPrime[i]) primes.push_back(i);
    len_primes = primes.size();
}

ll BinSearch(ll x, ll lo)
{
    ll pos = -1;
    ll hi = len_primes - 1;
    while(lo <= hi){
        ll m = (lo + hi) / 2;
        if(primes[m] <= x) lo = m + 1, pos = m;
        else hi = m - 1;
    }
    return pos;
}

ll Solve(ll n)
{
    n *= 2;
    ll i = 1;
    ll ans = 1;
    while(primes[i] <= n){
        ll pos = BinSearch(n - primes[i], i);
        ll g = primes[i], h = primes[pos];
        if(pos == -1) return ans;
        ans += pos - i + 1, i++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("goldbach.inp", "r", stdin);
    freopen("goldbach.out", "w", stdout);

    Sieve();
    ll n;
    while(cin >> n)
    {
        cout << Solve(n) << "\n";
    }

    return 0;
}
