#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll c;

ll add(ll a, ll b)
{
    if(b == 0) return a;
    ll t = add(a, b/2) % c;
    if(b % 2 == 0) return t + b/2;
    else return t + b/2 + 1;
}

ll mul(ll a, ll b)
{
    if(b == 0) return 0;
    ll t = mul(a, b/2) % c;
    t = add(t, t);
    if(b % 2 == 0) return t;
    else return add(t, a);
}

ll power(ll a, ll b)
{
    if(b == 0) return 1 % c;
    ll t = power(a, b/2) % c;
    t = mul(t, t);
    if(b % 2 == 0) return t;
    return mul(t, a);
}

int main()
{
    freopen("nosimple.inp", "r", stdin);
    freopen("nosimple.out", "w", stdout);

    ll a, b;
    cin >> a >> b >> c;
    cout << power(a, b);

    return 0;
}
