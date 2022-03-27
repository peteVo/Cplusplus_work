#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
ll const MAX_LL = 9223372036854775807;

ll k, n, a[100001];

void ReadData()
{
    cin >> n >> k;
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
}

void Solve()
{
    ll min_wait = MAX_LL, min_sum_wait = 9223372036854775807;
    ll start_for_min_sum_wait = 0, start_for_min_wait = -1;
    for(ll start = 0; start < k; ++start){
        ll wait = 0, sum_wait = 0;
        for(ll i = 1; i <= n; ++i){
            ll x;
            if(a[i] <= start) x = start - a[i];
            else x = (((a[i] - start - 1) / k) + 1) * k - (a[i] - start);
            wait = max(wait, x);
            sum_wait += x;
        }
        if(min_wait > wait){
            min_wait = wait;
            start_for_min_wait = start;
        }
        if(min_sum_wait > sum_wait){
            min_sum_wait = sum_wait;
            start_for_min_sum_wait = start;
        }
    }
    cout << min_sum_wait << " " << start_for_min_sum_wait << "\n" << min_wait << " " << start_for_min_wait << "\n";
}

int main()
{
    freopen("buses.inp", "r", stdin);
    freopen("buses.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ReadData();
    Solve();

    return 0;
}
