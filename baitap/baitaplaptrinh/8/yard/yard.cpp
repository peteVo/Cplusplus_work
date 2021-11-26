#include <iostream>
#include <cstdio>
#include <cmath>
#define maxN 220000

using namespace std;
typedef long long ll;

ll a[41] = {0};
ll numPrimes[41];
bool notPrime[maxN + 1] = {false};

void Sieve()
{
    notPrime[0] = notPrime[1] = true;
    int m = sqrt(maxN);
    for (int i = 2; i <= m; ++i)
    {
        if (!notPrime[i])
        {
            for (int j = i, cap = maxN / i; j <= cap; ++j)
            {
                notPrime[i * j] = true;
            }
        }
    }
}

void Maketiles()
{
    a[1] = 1, a[2] = 1, a[3] = 1;
    a[4] = 2;
    for (int i = 5; i <= 40; ++i)
    {
        a[i] = a[i - 1] + a[i - 4];
    }
}

void Makenumprimes()
{
    int i = 1, j = 1;
    int numprime = 0;
    for (i = 1; i <= 40; ++i)
    {
        while (j < a[i])
        {
            j++;
            if (!notPrime[j])
                numprime++;
        }
        numPrimes[i] = numprime;
    }
}

int main()
{
    freopen("yard.inp", "r", stdin);
    freopen("yard.out", "w", stdout);

    Sieve();
    Maketiles();
    Makenumprimes();
    //for (int i = 1; i <= 40; ++i)
    //{
    //    cout << "numPrimes[" << i << "] : " << numPrimes[i] << " a[" << i << "] : " << a[i] << endl;
    //}
    ll T, n;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cin >> n;
        cout << numPrimes[n] << endl;
    }

    return 0;
}
