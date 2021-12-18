#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int n, m;
char g[52][52];
bool visited[52][52] = {false};
char label[52][52];
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
vector<pii> a, b;

void ReadData()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            g[i][j] = s[j-1];
        }
    }
}

void FloodFill(int x, int y, char thelabel)
{
    if(x <= 0 || x > n || y <= 0 || y > m || g[x][y] == '.' || visited[x][y]) return;
    visited[x][y] = true;
    if(thelabel == 'a') a.push_back(pii(x, y));
    else b.push_back(pii(x, y));

    for(int i = 0; i < 4; ++i){
        FloodFill(x + dx[i], y + dy[i], thelabel);
    }
}

void CreateLabels()
{
    char currentlabel = 'a';
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(g[i][j] == 'X' && !visited[i][j]){
                FloodFill(i, j, currentlabel);
                currentlabel = (char)(currentlabel + 1);
            }
        }
    }
}

bool Valid(int x, int y)
{
    return x > 0 && x <= n && y > 0 && y <= m;
}

int Solve()
{
    int ans = 1e8;
    for(int i = 0, lena = a.size(); i < lenb; ++i){
        for(int j = 0, lenb = b.size(); j < lenb; ++j){
            ans = min(ans, (int)abs(b[j].first - a[i].first) + (int)abs(b[j].second - a[i].second) - 1);
        }
    }
    return ans;
}

int main()
{
    freopen("path.inp", "r", stdin);
    freopen("path.out", "w", stdout);

    ReadData();
    CreateLabels();
    cout << Solve();

    return 0;
}
