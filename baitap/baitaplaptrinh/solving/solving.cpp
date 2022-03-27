#include <iostream>
#include <cstdio>

typedef long long ll;
using namespace std;

ll SumAllDigits(ll n)
{
    ll ans = 0;
    while(n > 0){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

void Solve()
{
    bool flag = false;
    ll x;
    ll a, b, c; cin >> a >> b >> c;
    for(ll s_x = 1; s_x <= 99/*(9*9)*/; ++s_x){
        ll p = 1;
        for(int i = 0; i < a; ++i) p *= s_x;
        x = c + p*b;
        if(x > 1e9) break;
        if(SumAllDigits(x) == s_x) {
            flag = true;
            cout << x << "\n";
        }
    }
    if(flag == false) cout << "No solution\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("solving.inp", "r", stdin);
    freopen("solving.out", "w", stdout);

    Solve();

    return 0;
}
