#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

int base_trans(int n, int base)
{
    int ans = 0, mul = 1;
    while(n > 0){
        ans = ans + n % 10 * mul;
        mul *= base, n /= 10;
    }
    return ans;
}

int Solve()
{
    int min_base = 0;
    int a, b, c, temp; cin >> a >> b >> c;
    temp = a;
    while(temp > 0){
        min_base = max(min_base, temp % 10 + 1);
        temp /= 10;
    }
    temp = b;
    while(temp > 0){
        min_base = max(min_base, temp % 10 + 1);
        temp /= 10;
    }
    temp = c;
    while(temp > 0){
        min_base = max(min_base, temp % 10 + 1);
        temp /= 10;
    }

    for(int base = min_base; base <= 16; ++base){
        int x = base_trans(a, base), y = base_trans(b, base), z = base_trans(c, base);
        if(x * y == z) return base;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mult.inp", "r", stdin);
    freopen("mult.out", "w", stdout);

    cout << Solve();

    return 0;
}
