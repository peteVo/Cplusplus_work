#include <iostream>
#include <cstdio>

typedef long long ll;
using namespace std;

const int maxN = 2e6;

int n;
int a[2001];
int cnt[4000001] = {0};

int Solve()
{
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            cnt[a[i] + a[j] + maxN]++;

    for(int j = 1; j <= n; ++j){
        for(int i = j + 1; i <= n; ++i){
            cnt[a[i] + a[j] + maxN]--;
        }
        for(int i = 1; i < j; ++i)
            if(cnt[-(a[i] + a[j]) + maxN] > 0){
                ans += cnt[-(a[i] + a[j]) + maxN];
            }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("zeroquad.inp", "r", stdin);
    freopen("zeroquad.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << Solve();

    return 0;
}
