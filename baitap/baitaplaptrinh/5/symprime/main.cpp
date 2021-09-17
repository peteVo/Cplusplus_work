#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool notPrime[20000001] = {false};

void Sieve()
{
    notPrime[0] = true, notPrime[1] = true;
    int m = sqrt(20000000);
    for(int i = 2; i <= m; ++i){
        if(!notPrime[i]){
            for(int j = i; j <= 20000000/i; ++j) notPrime[i*j] = true;
        }
    }
}

bool isSymmetricPrime(int n)
{
    int i = n - 1, j = n + 1;
    while(notPrime[i]) i--;
    while(notPrime[j]) j++;
    return( (i + j) / 2 == n && !notPrime[n] );
}

int main()
{
    freopen("symprime.inp","r",stdin);
    freopen("symprime.out","w",stdout);

    Sieve();

    int test;
    cin >> test;
    for(int i = 0; i < test; ++i){
        int n;
        cin >> n;
        if(isSymmetricPrime(n)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
