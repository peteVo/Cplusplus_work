#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int dx[26] = {0}, dy[26] = {0};
int difx[4] = {0, 0, 1, -1}, dify[4] = {1, -1, 0, 0};
pii a[1002][1002];
bool inval[1002][1002] = {false}, mark[1002][1002] = {false};

void ReadData()
{
    dy['E'-'A'] = 1;
    dy['W'-'A'] = -1;
    dx['S'-'A'] = 1;
    dx['N'-'A'] = -1;

    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        string s; cin >> s;
        for(int j = 1; j <= m; ++j){
            a[i][j].first = dx[s[j-1]-'A'];
            a[i][j].second = dy[s[j-1]-'A'];
        }
    }
}
/*
int Solve()
{
    for(int offset_i = 0; offset_i <= (n-1)/2; ++offset_i){
        int i = 1 + offset_i;
        for(int offset_j = 0; offset_j <= (m-1)/2; ++offset_j){
            int j = 1 + offset_j;
            int u = i + a[i][j].first, v = j + a[i][j].second;
            if(u < 1 || u > n || v < 1 || v > m || inval[u][v] == true)
                inval[i][j] = true;

            j = m - offset_j;
            u = i + a[i][j].first, v = j + a[i][j].second;
            if(u < 1 || u > n || v < 1 || v > m || inval[u][v] == true)
                inval[i][j] = true;
        }

        i = n - offset_i;
        for(int offset_j = 0; offset_j <= (m-1)/2; ++offset_j){
            int j = 1 + offset_j;
            int u = i + a[i][j].first, v = j + a[i][j].second;
            if(u < 1 || u > n || v < 1 || v > m || inval[u][v] == true)
                inval[i][j] = true;

            j = m - offset_j;
            u = i + a[i][j].first, v = j + a[i][j].second;
            if(u < 1 || u > n || v < 1 || v > m || inval[u][v] == true)
                inval[i][j] = true;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(inval[i][j]) cout << "X ";
            else cout << "O ";
            //if(inval[i][j] == false) cnt++;
        }
        cout << "\n";
    }
    return cnt;
}
*/
bool Check(int x, int y)
{
    if(inval[x][y] == true) return true;
    int u = x + a[x][y].first, v = y + a[x][y].second;
    if(u < 1 || u > n || v < 1 || v > m || inval[u][v] == true){
        inval[x][y] = true;
        return true;
    }
    return false;
}

void DFS(int x, int y)
{
    if(Check(x, y)){
        mark[x][y] = true;
        for(int i = 0; i < 4; ++i){
            int u = x + difx[i], v = y + dify[i];
            if(u >= 1 && u <= n && v >= 1 && v <= m && !mark[u][v])DFS(u, v);
        }
    }
}

int Solve()
{
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            DFS(i, j);
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(inval[i][j] == false) cnt++;
        }
    }
    return cnt;
}

int main()
{
    freopen("itable.inp", "r", stdin);
    freopen("itable.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ReadData();
    cout << Solve();

    return 0;
}
