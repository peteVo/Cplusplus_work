#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n;
ll a[100001], b[100001];

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + n);
}

ll Solve()
{
    ull ans = 18446744073709551615;
    for(int i = 1; i <= n; ++i){
        ll *pointer = upper_bound(b + 1, b + 1 + n, -a[i]);
        ll z = *pointer; ll t = *(pointer - 1);
        ull q, p;

        if((z > 0) - (z < 0) != (a[i] > 0) - (a[i] < 0)){
            q = (ull)z + a[i];
        }
        else q = (ull)abs(z) + (ull)abs(a[i]);

        if((t > 0) - (t < 0) != (a[i] > 0) - (a[i] < 0)){
            p = (ull)t + a[i];
        }
        else p = (ull)abs(t) + (ull)abs(a[i]);

        if(q > p){
            if(p < ans) ans = p;
        }
        else if(q < ans) ans = q;
    }
    return ans;
}

int main()
{
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ReadData();
    cout << Solve();

    return 0;
}
