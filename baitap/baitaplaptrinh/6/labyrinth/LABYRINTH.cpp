#include <bits/stdc++.h>
using namespace std;

#define maxMN 1000
int m, n;
char a[maxMN][maxMN];

bool visited[maxMN][maxMN] = {false};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
string d[4] = {"W", "N", "E", "S"};
string ans = "";

void readData() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
}

bool check(int x, int y) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}

bool DFS(int x, int y) {
    visited[x][y] = true;
    if (x == m-1 || x == 0 || y == n-1 || y == 0)
        return true;
    for (int i = 0; i < 4; ++i) {
        int u = x + dx[i], v = y + dy[i];
        if (check(u, v) && a[u][v] == '.' && !visited[u][v]) {
            if (DFS(u, v)) {
                ans.insert(0, d[i]);
                return true;
            }
        }      
    }
    return false;
}

void solve() {
    int x, y;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] == '*') x = i, y = j;
    if (DFS(x, y))
        cout << ans;
}

int main() {
    freopen("LABYRINTH.inp", "r", stdin);
    freopen("LABYRINTH.out", "w", stdout);
    readData();
    solve();
    return 0;
}