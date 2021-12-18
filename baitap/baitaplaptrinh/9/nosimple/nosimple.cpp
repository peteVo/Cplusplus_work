#include <iostream>
#include <cstdio>

using namespace std;
typedef unsigned long long ull;

ull c;

ull add(ull a, ull b)
{
    if(b == 0) return a % c;
    ull t = add(a, b/2) % c;
    if(b % 2 == 0) return (t + b/2) % c;
    else return (t + b/2 + 1) % c;
}

ull mul(ull a, ull b)
{
    if(b == 0) return 0;
    ull t = mul(a, b/2) % c;
    t = add(t, t);
    if(b % 2 == 0) return t;
    else return add(t, a);
}

ull power(ull a, ull b)
{
    if(b == 0) return 1 % c;
    ull t = power(a, b/2) % c;
    t = mul(t, t);
    if(b % 2 == 0) return t;
    return mul(t, a);
}

int main()
{
    freopen("nosimple.inp", "r", stdin);
    freopen("nosimple.out", "w", stdout);

    ull a, b;
    cin >> a >> b >> c;
    cout << power(a, b);

    return 0;
}
