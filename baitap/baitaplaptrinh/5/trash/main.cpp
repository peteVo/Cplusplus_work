#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
ll n, t, x[1000001];

void ReadData()
{
    cin >> n >> t;
    for(int i = 1; i <= n; ++i) cin >> x[i];
}

ll Ways()
{
    /*
    int i = 1, j = 1;
    ll sum = x[i], ans = 0;


    while(i <= n && j <= n){
        if(sum <= t){
            ans = ans + (ll)j - (ll)i + 1;
            j++;
            sum += x[j];
        }
        else{
            sum -= x[i];
            i++;
        }
        if(i > j){
            j++;
            sum += x[j];
        }
    }
    */

    /////////// SHORTENED CODE ///////////

    ll sum = 0, ans = 0;
    x[n + 1] = t + 1;

    for(ll i = 1, j = 0; i <= n; ++i){

        while(sum <= t){
            sum = sum + x[++j];
        }

        ans = ans + j - i; ///// j is off by 1 digit, thus ans = ans + j - i and not ans = ans + j - i + 1 //////
        sum -= x[i];
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("trash.inp", "r", stdin);
    freopen("trash.out", "w", stdout);

    ReadData();
    cout << Ways();

    return 0;
}
