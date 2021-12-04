#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;
int m, n;
int h[1001][1001] = {0};
bool notinvalley[1001][1001] = {false};
bool visited[1001][1001] = {false};
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void ReadData()
{
    cin >> m >> n;
    for(int i = 1 ; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> h[i][j];
        }
    }
}

void Update(int x, int y, int& maxh)
{
    if(maxh <= h[x][y]){
        maxh = h[x][y];
        notinvalley[x][y] = true;
    }
}

void MakeNotInValley()
{
    int maxh = INT_MIN;
    for(int i = 1; i <= m; ++i){
        // left to right
        maxh = INT_MIN;
        for(int j = 1; j <= n; ++j) Update(i, j, maxh);

        // right to left
        maxh = INT_MIN;
        for(int j = n; j > 0; --j) Update(i, j, maxh);
    }
    for(int j = 1; j <= n; ++j){
        // top to bottom
        maxh = INT_MIN;
        for(int i = 1; i <= m; ++i) Update(i, j, maxh);

        // bottom to top
        maxh = INT_MIN;
        for(int i = m; i > 0; --i) Update(i, j, maxh);
    }
}

int DFS(int x, int y)
{
    visited[x][y] = true;
    int ans = 1;
    for(int i = 0; i < 4; ++i){
        int u = x + dx[i], v = y + dy[i];
        if(u > 0 && u <= m && v > 0 && v <= n && !visited[u][v] && !notinvalley[u][v])
            ans = ans + DFS(u, v);
    }
    return ans;
}

int Solve()
{
    int ans = 0;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(!visited[i][j] && !notinvalley[i][j])
                ans = max(ans, DFS(i, j));
        }
    }
    //cout << DFS(3, 6);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("valley.inp", "r", stdin);
    freopen("valley.out", "w", stdout);

    ReadData();
    MakeNotInValley();
/*
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            char c = notinvalley[i][j] + '0';
            if(notinvalley[i][j]) c = '.';
            cout << c << " ";
        }
        cout << endl;
    }
*/
    cout << Solve();

    return 0;
}
