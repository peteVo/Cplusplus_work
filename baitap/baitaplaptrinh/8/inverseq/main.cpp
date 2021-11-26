#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll pow2[60];
ll n;

void MakePow2()
{
    pow2[0] = 1;
    for(ll i = 1; i <= 59 /* 59 = log2(1e18) */ ; ++i){
        pow2[i] = pow2[i-1] * 2;
    }
}

ll UpperBound(ll num)
{
    ll* it = upper_bound(pow2, pow2 + 60, num) - 1;
    if(*it >= num) return *(it - 1);
    else return *it;
}

ll Solve(ll n, ll reverse)
{
    if(n == 1) return reverse;
    if(n == 2) return 1 - reverse;
    return Solve(n - UpperBound(n), 1 - reverse);
}

int main()
{
    freopen("inverseq.inp", "r", stdin);
    freopen("inverseq.out", "w", stdout);

    MakePow2();
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll n;
        cin >> n;
        cout << Solve(n, 0) << endl;
    }

    return 0;
}
