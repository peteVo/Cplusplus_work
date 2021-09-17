#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
int m, n;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
typedef pair<int, int> pii;
bool mark[101][101] = {false};
char a[101][101];

void ReadData()
{
    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < n; ++j){
            a[i][j+1] = s[j];
        }
    }
}

bool ValidCell(int x, int y)
{
    return((x>0 && x<=m) && (y>0 && y<=n));
}

int BFS(int r, int c)
{
    queue<pii> Q;
    Q.push(pii(r, c));
    mark[r][c] = true;
    //cout << "cell mark[" << r << "][" << c << "] marked to true" << endl;
    int res = 1;

    while(!Q.empty()){
        r = Q.front().first, c = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; ++i){
            int x = r + dr[i], y = c + dc[i];
            if(ValidCell(x, y) && !mark[x][y] && a[x][y] == '#'){
                ++res;
                Q.push(pii(x, y));
                mark[x][y] = true;
                //cout << "cell mark[" << x << "][" << y << "] marked to true in tribute to cell mark[" << r << "][" << c << "]" << endl;
            }
        }
    }
    return res;
}

int Solve()
{
    int ans = 0;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(!mark[i][j] && a[i][j] == '#'){
                ans++;
                BFS(i, j);
            }
        }
    }
    return ans;
}

int main()
{
    freopen("remsqr.inp", "r", stdin);
    freopen("remsqr.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
