#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
typedef unsigned long long ull;

ull b;

ull add(ull x, ull y)
{
    if(y == 0) return x % b;
    ull t = add(x, y/2) % b;
    if(y & 1) return (t + y/2 + 1) % b;
    return (t + y/2) % b;
}

ull mul(ull x, ull y)
{
    if(y == 0) return 0;
    ull t = mul(x, y/2) % b;
    t = add(t, t); // t = 2t
    if(y & 1) return add(t, x);
    return t;
}

ull power(ull a, ull k)
{
    if(k == 0) return 1 % b;
    ull t = power(a, k/2) % b;
    t = mul(t, t);
    if(k & 1) return mul(t, a);
    return t;
}

int main()
{
    freopen("digit.inp", "r", stdin);
    freopen("digit.out", "w", stdout);

    ull a, k;
    cin >> a >> b >> k;
    a = a % b;
    //cout << a << endl;
    cout << mul(a, power(10, k - 1)) * 10 / b % 10;

    return 0;
}
