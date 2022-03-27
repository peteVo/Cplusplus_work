#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll F[1000001] = {0};

void Prep()
{
    F[1] = 1, F[2] = 1;
    for(int i = 3; i <= 1000000; ++i) F[i] = (F[i-1] + F[i-2]) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("gym.inp", "r", stdin);
    freopen("gym.out", "w", stdout);

    Prep();
    ll t, n; cin >> t;
    while(t--){
        cin >> n;
        cout << F[n+2] - 1 << "\n";
    }

    return 0;
}
