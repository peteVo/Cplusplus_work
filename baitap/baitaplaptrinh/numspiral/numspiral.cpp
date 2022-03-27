#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

ll Solve(ll x, ll y)
{
    if(y > x)
    {
        if(y & 1)
            return (y-1)*(y-1) + 2*y - x;
        else return (y-1)*(y-1) + x;
    }
    else //if(x > y)
    {
        if(x & 1)
            return (x-1)*(x-1) + y;
        else return (x-1)*(x-1) + 2*x - y;
    }
}

int main()
{
    freopen("numspiral.inp", "r", stdin);
    freopen("numspiral.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t; cin >> t;
    /*for(int i = 1; i <= 5; ++i){
        for(int j = 1; j <= 5; ++j){
            cout << Solve(i, j) << " ";
        }
        cout << "\n";
    }*/
    while(t--)
    {
        ll x, y; cin >> x >> y;
        cout << Solve(x, y) << "\n";
    }

    return 0;
}
