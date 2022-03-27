#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int n, l, r;
int rt[100001] = {0};
int line_chosen[100001];
struct line
{
    int l, r;
    int pos;
} a[100001];

bool cmp(line x, line y)
{
    return(x.l < y.l || (x.l == y.l && x.r > y.r));
}

void ReadData()
{
    cin >> n >> l >> r;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].l >> a[i].r;
        a[i].pos = i;
    }
    sort(a + 1, a + 1 + n, cmp);

    for(int i = 1; i <= n; ++i){
        if(rt[a[i].l] < a[i].r){
            rt[a[i].l] = a[i].r;
            line_chosen[a[i].l] = a[i].pos;
        }
    }
    for(int i = 1; i <= 1e5; ++i){
        if(i == 1) continue;
        if(rt[i] < rt[i-1]){
            if(rt[i-1] > i){
                rt[i] = rt[i-1];
                line_chosen[i] = line_chosen[i-1];
            }
        }
    }
}

void Solve()
{
    if(l == r){
        cout << "1\n";
        cout << line_chosen[l];
    }
    vector<int> ans;
    int cnt = 0;
    while(l < r){
        cnt++;
        ans.push_back(line_chosen[l]);
        l = rt[l];
        if(l == 0 || l == rt[l]){
            cout << "-1\n";
            return;
        }
    }
    cout << cnt << "\n";
    for(int i = 0; i < cnt; ++i) {
        cout << ans[i] << "\n";
    }
}

int main()
{
    freopen("cover.inp", "r", stdin);
    freopen("cover.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ReadData();
    Solve();

    return 0;
}
