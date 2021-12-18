#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

pii FS(ll n)
{
    for(unsigned i = 0; i <= n; ++i)
        for(unsigned j = i; j <= n; ++j){
            if(i*i + j*j == n)
                return pii(i, j);
            if(i*i + j*j > n) break;
        }
    return pii(-1, -1);
}

int main()
{
    freopen("fs.inp", "r", stdin);
    freopen("fs.out", "w", stdout);

    ll S;
    cin >> S;
    pii ans = FS(S);
    if(ans.first == -1 && ans.second == -1){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "0 0" << endl;
    cout << ans.first << " " << ans.second << endl;
    cout << ans.first - ans.second << " " << ans.second + ans.first << endl;
    cout << -ans.second << " " << ans.first << endl;


    return 0;
}
