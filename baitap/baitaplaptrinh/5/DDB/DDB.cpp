#include <iostream>
#include <cstdio>
#include <cmath>
#define maxN 2000000

using namespace std;

bool notPrime[maxN + 1] = {false};
int PrefixSumArray[maxN + 1];

void Sieve()
{
    notPrime[0] = true;
    notPrime[1] = true;
    int m = sqrt(maxN);
    for(int i = 2; i <= m; ++i){
        if(!notPrime[i])
            for(int j = i; j <= maxN / i; j ++) notPrime[i * j] = true;
    }
}

void CreatePrefixSumArray()
{
    int sum = 0;
    for(int i = 1; i <= maxN; ++i) {
        if(!notPrime[i]) sum++;
        PrefixSumArray[i] = sum;
    }
}

//mang cong don tinh so cac so nguyen to
int numOfPrimes(int n)
{

    return PrefixSumArray[n * 2] - PrefixSumArray[n];

}

int main()
{
    freopen("DDB.inp", "r", stdin);
    freopen("DDB.out", "w", stdout);

    Sieve();

    CreatePrefixSumArray();

    int test, n;

    cin >> test;

    for(int i = 0; i < test; ++i) {
        cin >> n;
        cout << numOfPrimes(n) << endl;
    }

    return 0;
}
