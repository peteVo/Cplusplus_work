#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

void Solve()
{
    int n; cin >> n;
    int a[10001];
    for(int i = 1; i <= n; ++i) cin >> a[i];

    bool flag = false;
    for(int i = n; i >= 2; --i){
        if(a[i-1] < a[i]){
            int m = 1e9, pos = 1e9;
            for(int j = i; j <= n; ++j)
                if(a[j] > a[i-1] && m > a[j])
                    m = a[j], pos = j;
            swap(a[i-1], a[pos]);
            for(int k = 0; k <= (n - i - 1) / 2; ++k){
                //cout << "swap " << a[i + k] << " with " << a[n - k] << "\n";
                swap(a[i + k], a[n - k]);
            }
            flag = true;
            break;
        }
    }
    if(flag) for(int i = 1; i <= n; ++i) cout << a[i] << " ";
    else cout << "-1";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("permutationgen.inp", "r", stdin);
    freopen("permutationgen.out", "w", stdout);

    Solve();

    return 0;
}
