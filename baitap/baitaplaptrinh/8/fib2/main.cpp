#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
ll Fib[60], FibA[60];

void MakeFibonacciNums()
{
    Fib[0] = Fib[1] = FibA[0] = 1, FibA[1] = 0;
    for(int i = 2; i <= 45; ++i){
        Fib[i] = Fib[i-2] + Fib[i-1];
        FibA[i] = FibA[i-2] + FibA[i-1];
    }
}


ll Solve(int n, int k, ll sum)
{
    //if(n == 0) { cout << "n == 0 -> sum = " << sum + 1 << endl; return sum + 1; }
    //if(n == 1) { cout << "n == 1 -> sum = " << sum << endl; return sum;     }
    //if(k <= Fib[n-2]) { cout << "k <= " << Fib[n-2] << endl; return Solve(n - 2, k, sum); }
    //cout << "k > " << Fib[n-2] << endl;
    //return Solve(n - 1, k - Fib[n-2], sum + FibA[n-2]);
    if(n == 0) return sum + 1;
    if(n == 1) return sum;
    if(k <= Fib[n-2]) return Solve(n - 2, k, sum);
    return Solve(n - 1, k - Fib[n-2], sum + FibA[n-2]);
}

int main()
{
    freopen("fib2.inp", "r", stdin);
    freopen("fib2.out", "w", stdout);

    MakeFibonacciNums();
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int n, k;
        cin >> n >> k;
        cout << Solve(n, k, 0) << endl;
    }

    return 0;
}
