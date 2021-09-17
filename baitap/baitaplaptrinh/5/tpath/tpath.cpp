#include <iostream>
#include <cstdio>

using namespace std;

bool notPrime[1000001] = {false};

typedef long long ll;

ll n, m, i, a[1501][1501];

void Sieve()
{
    notPrime[0] = true, notPrime[1] = true;
    for(ll i = 2; i <= 1000; ++i){
        if(!notPrime[i]){
            for(ll j = i; j <= 1000000 / i; ++j) notPrime[i * j] = true;
        }
    }
}

void ReadData()
{
    cin >> n >> m;

    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }
}

void Solve()
{
    ll primes = 0, total = 0;
    ll hor, ver, dia;

    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j){
            hor = ver = dia = a[i][j];
            if(!notPrime[a[i][j]]) { primes++; total+=a[i][j]; /*cout << a[i][j] << endl;*/ }
            else if(a[i][j] == 0) continue;
            for(ll k = 1; k <= 5; ++k){
                if(j + k <= m){
                    hor = hor * 10 + a[i][j + k];
                    if(!notPrime[hor]) { primes++; total += hor; /*cout << "hor : " << hor << endl;*/ }
                }
                if(i + k <= n){
                    ver = ver * 10 + a[i + k][j];
                    if(!notPrime[ver]) { primes++; total += ver; /*cout << "ver : " << ver << endl;*/ }
                }
                if(i + k <= n && j + k <= m){
                    dia = dia * 10 + a[i + k][j + k];
                    if(!notPrime[dia]) { primes++; total += dia; /*cout << "dia : " << dia << endl;*/ }
                }

            }
        }
    }
    cout << primes << " " << total;
}

int main()
{
    freopen("tpath.inp", "r", stdin);
    freopen("tpath.out", "w", stdout);

    ReadData();
    Sieve();

    Solve();

    //for(ll i = 1; i <= n; ++i){
    //    for(ll j = 1; j <= m; ++j) cout << a[i][j];
    //    cout << endl;
    //}

    return 0;
}
