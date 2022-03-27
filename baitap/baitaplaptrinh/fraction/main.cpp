#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const ll maxN = 1e6;

ll freqa[maxN+1] = {0}, freqb[maxN+1] = {0};
bool notPrime[maxN+1] = {false};
vector<ll> p;

ll logarithm(ll x, ll base)
{
    return log2(x) / log2(base);
}

void clearFreq()
{
    for(int i = 0; i <= maxN; ++i)
        freqa[i] = 0, freqb[i] = 0;
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
    for(int i = 2; i <= maxN; ++i){
        if(!notPrime[i])
            p.push_back(i);
    }
    /*for(int i = 0; i < 5; ++i){
        cout << p[i] << "\n";
    }*/
}

void Extract(ll x, ll *freq)
{
    if(x < 2) return;
    if(!notPrime[x]){
        freq[x]++;
        return;
    }
    ll i = 0;
    while(x > 1)
    {
        ll y = p[i];
        ll h = 0;
        if(x % p[i] == 0)
            x /= p[i], freq[p[i]]++;
        else i++;
    }
}

void Solve()
{
    ll n; cin >> n;
    clearFreq();
    for(int i = 1; i <= n; ++i){
        ll x; cin >> x;
        Extract(x, freqa);
    }
    for(int i = 1; i <= n; ++i){
        ll x; cin >> x;
        Extract(x, freqb);
    }
    for(int i = 2; i <= maxN; ++i){
        freqb[i] -= freqa[i];
        if(freqb[i] > 0 && i != 2 && i != 5){
            cout << "repeating\n";
            return;
        }
    }
    cout << "finite\n";
    return;
}

int main()
{
    freopen("fraction.inp", "r", stdin);
    freopen("fraction.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Sieve();
    ll T; cin >> T;
    while(T--)
        Solve();

    return 0;
}
