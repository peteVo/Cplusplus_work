#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n, m[53][53];
typedef pair<int, int> pii;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
bool mark[33][33] = {false};

void ReadData()
{
    cin >> n;
    string s;

    for(int i = 1; i <= n; ++i){
        cin >> s;
        for(int j = 1; j <= n; ++j){
            m[i][j] = (s[j-1] == '.');
        }
    }
}

bool ValidCell(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= n && m[x][y] == 1);
}

int wallArea(int r, int c)
{
    queue<pii> Q;
    Q.push(pii(r, c));
    mark[r][c] = true;
    int ans = 0;
    while(!Q.empty()){
        pii p = Q.front();
        Q.pop();
        for(int i = 0; i < 4; ++i){
            int x = p.first + dr[i], y = p.second + dc[i];
            if(!ValidCell(x, y)) ++ans;
            else if (mark[x][y] == false)
            {
                Q.push(pii(x, y));
                mark[x][y] = true;
            }
        }
    }
    return ans;
}

int main()
{
    freopen("mirror.inp", "r", stdin);
    freopen("mirror.out", "w", stdout);

    ReadData();
    int ans = wallArea(1, 1);
    if (mark[n][n] == false)
        ans = ans + wallArea(n, n);
    cout << 9*(ans - 4);
    return 0;
}
