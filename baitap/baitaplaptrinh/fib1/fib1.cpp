#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll fib[46] = {0};

void MakeFibonacci()
{
    fib[0] = fib[1] = 1;
    for(int i = 2; i <= 45; ++i){
        fib[i] = fib[i-2] + fib[i-1];
    }
}

char Solve(ll n, ll k)
{
    if(n == 0) return 'a';
    if(n == 1) return 'b';
    if(k <= fib[n-2]) return Solve(n - 2, k);
    return Solve(n - 1, k - fib[n-2]);
}

int main()
{
    freopen("fib1.inp", "r", stdin);
    freopen("fib1.out", "w", stdout);

    MakeFibonacci();
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        ll n, k;
        cin >> n >> k;
        cout << Solve(n, k) << endl;
    }

    return 0;
}
