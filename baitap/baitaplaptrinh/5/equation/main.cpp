#include <iostream>
#include <cstdio>
#include <cmath>

#define maxK 5000

using namespace std;

bool notPrime[maxK + 1] = {false};

void Sieve()
{
    notPrime[0] = true;
    notPrime[1] = true;
    int m = sqrt(maxK);
    for(int i = 2; i <= m; i++){
        if(!notPrime[i]){
            for(int j = i; j <= maxK / i; j++) notPrime[i*j] = true;
        }
    }
}

int numEquations(int K)
{
    int cnt = 0;
    for(int i = 2; i < K; ++i)
        if(!notPrime[i])
            for(int j = i; j < K - i; ++j)
                if(!notPrime[j] && K - i - j >= j && !notPrime[K - i - j]) cnt++;
    return cnt;
}

int main()
{
    freopen("equation.inp","r",stdin);
    freopen("equation.out","w",stdout);

    Sieve();
    int K;

    while(cin >> K){
        cout << numEquations(K) << endl;
    }

    return 0;
}
