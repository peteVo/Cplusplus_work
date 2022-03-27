#include <iostream>
#include <cstdio>

using namespace std;

void Solve()
{
    int n, m;
    int a[10001];
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) cin >> a[i];

    bool flag = false;
    for(int i = m; i >= 1; --i){
        if(a[i] < n - m + i){
            a[i]++;
            for(int j = i + 1; j <= m; ++j)
                a[j] = a[j-1] + 1;
            flag = true;
            break;
        }
    }
    if(flag) for(int i = 1; i <= m; ++i) cout << a[i] << " ";
    else cout << "-1";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("combinationgen.inp", "r", stdin);
    freopen("combinationgen.out", "w", stdout);

    Solve();

    return 0;
}
