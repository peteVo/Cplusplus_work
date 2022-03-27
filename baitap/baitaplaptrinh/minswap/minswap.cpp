#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int a[100001];

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
}

int Solve()
{
    pair<int, int> arr[100001];
    for(int i = 1; i <= n; ++i)
        arr[i].first = a[i], arr[i].second = i;
    sort(arr + 1, arr + 1 + n);

    bool vis[100001] = {false};

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(vis[i] || arr[i].second == i)
            continue;
        int cycle_size = 0, j = i;
        while(!vis[j]){
            vis[j] = true;
            j = arr[j].second;
            cycle_size++;
        }
        ans += cycle_size - 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("minswap.inp", "r", stdin);
    freopen("minswap.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
