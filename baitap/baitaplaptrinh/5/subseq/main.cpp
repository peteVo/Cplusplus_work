#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll a[1000001], s[1000001] = {0}, n, k, sMin[1000001] = {0};

void ReadData()
{
    cin >> n >> k;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
}

void MakeMinSum()
{
    sMin[1] = s[1];
    for(ll i = 2; i <= n; ++i) sMin[i] = min(sMin[i - 1], s[i]);
}

ll sumSubSeq()
{
    ll ans = -1e10;
    for(ll hi = k; hi <= n; ++hi){
        ans = max(ans, s[hi] - sMin[hi - k]);
    }
    return ans;
}

int main()
{
    freopen("subseq.inp", "r", stdin);
    freopen("subseq.out", "w", stdout);

    ReadData();
    MakeMinSum();

    cout << sumSubSeq();

    return 0;
}
