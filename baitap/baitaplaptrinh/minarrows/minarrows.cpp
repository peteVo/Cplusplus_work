#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int h[1000001] = {0}, arrow[1000001] = {0};

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> h[i];
}

int Solve()
{
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int curarrow = arrow[h[i]], height = h[i];
        if(arrow[h[i]] <= 0) ans++;
        else arrow[h[i]]--;
        arrow[h[i]-1]++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("minarrows.inp", "r", stdin);
    freopen("minarrows.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
