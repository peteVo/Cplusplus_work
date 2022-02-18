#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n;
int n1, n2, m1, m2;
int container[2001];
int a[1001], b[1001];
int comb_a[500001], comb_b[500001];

void ReadData()
{
    cin >> n;
    n1 = n/2, n2 = n - n1;
    m1 = n1*(n1-1)/2, m2 = n2*(n2-1)/2;

    for(int i = 1; i <= n; ++i) cin >> container[i];
    sort(container + 1, container + 1 + n);

    for(int i = 1; i <= n1; ++i) a[i] = container[i];
    for(int j = n1 + 1; j <= n; ++j) b[j - n1] = container[j];

    sort(a + 1, a + n1 + 1);
    sort(b + 1, b + n2 + 1);

    int cnt_a = 1, cnt_b = 1;
    for(int i = 1; i <= n1; ++i){
        for(int j = i + 1; j <= n1; ++j){
            comb_a[cnt_a++] = a[i] + a[j];
        }
    }
    for(int i = 1; i <= n2; ++i){
        for(int j = i + 1; j <= n2; ++j){
            comb_b[cnt_b++] = b[i] + b[j];
        }
    }
    sort(comb_a + 1, comb_a + m1 + 1);
    sort(comb_b + 1, comb_b + m2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("zeroquad.inp", "r", stdin);
    freopen("zeroquad.out", "w", stdout);

    ReadData();
    int ans = 0;
    for(int i = 1; i <= m1; ++i){
        ans += upper_bound(comb_b + 1, comb_b + m2 + 1, 0 - comb_a[i]) - lower_bound(comb_b + 1, comb_b + m2 + 1, 0 - comb_a[i]);
        cout << comb_a[i] << " " << *upper_bound(comb_b + 1, comb_b + m2 + 1, 0 - comb_a[i]) << " " << *lower_bound(comb_b + 1, comb_b + m2 + 1, 0 - comb_a[i]) << endl;
    }
    cout << ans << "\n";

    return 0;
}
