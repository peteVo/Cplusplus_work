#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

bool notPrime[1000001];

vector<int> hprimes;

void Sieve()
{
    notPrime[0] = true, notPrime[1] = true;
    int m = sqrt(1000000);
    for(int i = 2; i <= m; ++i){
        if(!notPrime[i]){
            for(int j = i; j <= 1000000/i; ++j) notPrime[i*j] = true;
        }
    }
}

int numCount(int x)
{
    int cnt = 0;
    while( x > 0 ){
        cnt = cnt + x % 10;
        x /= 10;
    }
    return cnt;
}

void listHPrimes(int n, int h)
{
    for(int i = 1; i <= n; ++i){
        if(!notPrime[i] && numCount(i) == h) hprimes.push_back(i);
    }
    cout << hprimes.size() << endl;
    for(int i = 0; i < hprimes.size(); ++i) cout << hprimes[i] << endl;
}


int main()
{
    freopen("hprime.inp", "r", stdin);
    freopen("hprime.out", "w", stdout);

    Sieve();

    int n, h;
    cin >> n >> h;

    listHPrimes(n,h);

    return 0;
}
