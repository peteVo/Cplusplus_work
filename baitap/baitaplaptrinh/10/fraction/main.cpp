#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("fraction.inp", "r", stdin);
    freopen("fraction.out", "w", stdout);

    ll n; cin >> n; n++;
    vector<bool> turn;
    while(n > 1){
        if(n&1) turn.push_back(false);
        else turn.push_back(true);
        n /= 2;
    }
    reverse(turn.begin(), turn.end());
    pair<ll, ll> ans(1, 1);
    for(vector<bool>::iterator it = turn.begin(); it != turn.end(); ++it){
        if(*it) ans.second = ans.first + ans.second;
        else ans.first = ans.first + ans.second;
    }
    cout << ans.first << " " << ans.second;

    return 0;
}
