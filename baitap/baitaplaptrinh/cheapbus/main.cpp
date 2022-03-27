#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

void Solve()
{
    ll n, cost[11];
    for(int i = 1; i <= 10; ++i) cin >> cost[i];
    cin >> n;

    ll trips[151][11] = {0};

    ll m[151] = {0};
    for(int i = 1; i <= min(n, (ll)10); ++i){
        m[i] = cost[i];
        trips[i][i] = 1;
        for(int z = 1; z <= i/2; ++z){
            if(m[i] > m[z] + m[i-z]){
                for(int j = 1; j <= 10; ++j){
                    trips[i][j] = 0;
                }
                for(int j = 1; j <= 10; ++j){
                    trips[i][j] = trips[z][j] + trips[i-z][j];
                }
                m[i] = m[z] + m[i-z];
            }
            //cout << "m[" << i << "] = " << m[i] << endl;
        }
    }
    for(int i = 11; i <= n; ++i){
        m[i] = 9223372036854775807;
        for(int z = 1; z <= i/2; ++z){
            if(m[i] > m[z] + m[i-z]){
                for(int j = 1; j <= 10; ++j){
                    trips[i][j] = 0;
                }
                for(int j = 1; j <= 10; ++j){
                    trips[i][j] = trips[z][j] + trips[i-z][j];
                }
                m[i] = m[z] + m[i-z];
            }
            //cout << "m[" << i << "] = " << m[i] << endl;
        }
    }

    /*for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= 10; ++j){
            cout << trips[i][j] << " ";
        }
        cout << endl;
    }*/

    for(int j = 1; j <= 10; ++j){
        for(int i = 1; i <= trips[n][j]; ++i){
            cout << j << "\n";
        }
    }
    cout << m[n] << "\n";
}

int main()
{
    freopen("cheapbus.inp", "r", stdin);
    freopen("cheapbus.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();

    return 0;
}
