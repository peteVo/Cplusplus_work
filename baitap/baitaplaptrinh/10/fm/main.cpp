#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, m;
ll a[1000001];

void ReadData()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
}

ll Solve()
{
    ll ans = 0;
    ll i = 1, j = n;
    while(i < j){
        while(a[i] + a[j] > m){
            if(j - i <= 1) return ans;
            else j--;
        }
        ans += j - i;
        i++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("fm.inp", "r", stdin);
    freopen("fm.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
