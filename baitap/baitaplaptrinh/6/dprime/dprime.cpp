#include <iostream>
#include <cstdio>
#include <cmath>
#define maxN 1000000
#define maxPrime 78498

using namespace std;
typedef long long ll;

bool notPrime[maxN + 1] = {false};
ll primes[maxPrime + 1];
ll smushedPrimes[maxPrime / 2 + 1];

//prototypes
void Sieve();
bool isPrime(ll n);
ll AddTwoNums(ll a, ll b);
void MakeSmushedArray();

void Sieve()
{
    notPrime[0] = notPrime[1] = true;
    ll m = sqrt(maxN);
    for(ll i = 2; i <= m; ++i){
        if(!notPrime[i]){
            for(ll j = i; j <= maxN / i; ++j){
                notPrime[i * j] = true;
            }
        }
    }
    ll cnt = 1;
    for(ll i = 2; i <= maxN; ++i){
        if(!notPrime[i]){
            primes[cnt] = i;
            cnt++;
        }
    }
}

bool isPrime(ll n)
{
    if(n < 2) return false;
    ll m = sqrt(n);

    ll i = 1;
    while(primes[i] < m){
        if(n % primes[i++] == 0) return false;
    }
    return true;
}

void MakeSmushedArray()
{
    ll cnt = 1;
    ll smushedArraySize = maxPrime / 2;
    for(ll i = 1; i <= maxPrime; i+=2){
        ll placeHolder = AddTwoNums(primes[i], primes[i+1]);

        if( (placeHolder <= maxN && !notPrime[placeHolder])
           || (placeHolder > maxN && isPrime(placeHolder)) )
        {
            smushedPrimes[cnt++] = placeHolder;
        }

        if(cnt > 1000) return;
    }
}

ll AddTwoNums(ll a, ll b)
{
    ll c = 0, mul = 1;
    while(b > 0){
        c = c + b % 10 * mul;
        mul *= 10;
        b /= 10;
    }
    return a * mul + c;
}

int main()
{
    freopen("dprime.inp", "r", stdin);
    freopen("dprime.out", "w", stdout);

    Sieve();
    MakeSmushedArray();
    //int cnt = 0;
    //for(int i = 1; i <= maxN; ++i) if(!notPrime[i]) cnt++;
    //cout << cnt;
    //cout << isPrime(2);

    int n;
    cin >> n;
    cout << smushedPrimes[n];

    return 0;
}
