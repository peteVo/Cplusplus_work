#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

const int INF = 1e9;
int m, n;
int a[202][202] = {0};
int f[202][202] = {0};
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void ReadData()
{
    cin >> m >> n;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            f[i][j] = INF;
        }
}

int Solve()
{
    queue<pii> q;
    for(int i = 1; i <= m; ++i) {f[i][1] = a[i][1]; q.push(pii(i, 1));}
    while(!q.empty()){
        int u = q.front().first, v = q.front().second; q.pop();
        for(int k = 0; k < 4; ++k){
            int i = u + dx[k], j = v + dy[k];
            if(i >= 1 && i <= m && j >= 1 && j <= n && f[i][j] > f[u][v] + a[i][j]){
                f[i][j] = f[u][v] + a[i][j];
                q.push(pii(i, j));
            }
        }
    }

    int min_val = INF;
    for(int i = 1; i < m; ++i) min_val = min(min_val, f[i][n]);
    return min_val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("funfair.inp", "r", stdin);
    freopen("funfair.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
