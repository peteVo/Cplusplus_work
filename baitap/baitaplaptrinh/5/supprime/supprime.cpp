#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

/*
bool primeSieve[50000] = {false};

vector<int> firstPrimeArray;
vector<int> superPrimeArray;

void Sieve()
{
    primeSieve[0] = primeSieve[1] = true;
    int m = sqrt(50000);
    for(int i = 2; i < m; ++i){
        if(!primeSieve[i]){
            for(int j = i; j < 50000 / i; ++j) primeSieve[i*j] = true;
            firstPrimeArray.push_back(i);
        }
    }
}

int SuperPrime(int x)
{
    for(int i = 1; i <= firstPrimeArray.size(); ++i){
        if(!primeSieve[i]) superPrimeArray.push_back(firstPrimeArray[i-1]);
    }
    return superPrimeArray[x-1];
}*/

bool notPrime[1000001] = {false};

vector<int> primeFirst;
vector<int> primeSecond;

void Sieve()
{
    notPrime[0] = true, notPrime[1] = true;
    int m = sqrt(1000000);

    for(int i = 2; i <= m; ++i){
        if(!notPrime[i])
            for(int j = i; j <= 1000000 / i; ++j) notPrime[i * j] = true;
    }
}

void SieveOutSuperPrimes()
{
    //Setup first array of primes
    for(int i = 2; i <= 1000000; ++i)
        if(!notPrime[i]) primeFirst.push_back(i);

    for(int i = 1; i < primeFirst.size(); ++i){
        if(!notPrime[i + 1]) primeSecond.push_back(primeFirst[i]);
    }
}

int main()
{
    freopen("supprime.inp", "r", stdin);
    freopen("supprime.out", "w", stdout);

    Sieve();

    SieveOutSuperPrimes();

    int k;
    cin >> k;

    cout << primeSecond[k - 1];

    return 0;
}
