#include <iostream>
#include <cstdio>
#include <cmath>

const int maxN = 500000, maxhat = 1000000;
const long long MOD = 1000000007;
using namespace std;

int m, n;
int a[maxN+1], b[maxN+1];
int a_hats[maxhat+1] = {0}, b_hats[maxhat+1] = {0};
int d[maxhat+1] = {0};

void Sieve()
{
    int s = sqrt(maxhat);
    for(int i = 2; i <= s; ++i){
        if(!d[i]){
            for(int j = i, len = maxhat/i; j <= len; ++j){
                d[i*j] = i;
            }
        }
    }
}

void ReadData()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= m; ++i){
        cin >> b[i];
    }
}

void Factorize(int x, int arr[])
{
    while(x > 1){
        int p = d[x];
        if(p == 0) p = x;
        while(x % p == 0){
            arr[p]++;
            x /= p;
        }
    }
}

long long Power(int x, int power)
{
    long long ans = 1;
    for(int i = 0; i < power; ++i){
        ans = ans * (long long)x % MOD;
    }
    return ans;
}

void Solve()
{
    for(int i = 1; i <= n; ++i){
        Factorize(a[i], a_hats);
    }
    for(int i = 1; i <= m; ++i){
        Factorize(b[i], b_hats);
    }
    long long GCD = 1, LCM = 1;
    for(int i = 2; i <= maxhat; ++i){
        GCD = GCD * Power(i, min(a_hats[i], b_hats[i])) % MOD;
        LCM = LCM * Power(i, max(a_hats[i], b_hats[i])) % MOD;
    }
    cout << GCD << endl << LCM << endl;
}

int main()
{
    freopen("gcdlcm.inp", "r", stdin);
    freopen("gcdlcm.out", "w", stdout);

    Sieve();
    ReadData();
    Solve();

    return 0;
}
