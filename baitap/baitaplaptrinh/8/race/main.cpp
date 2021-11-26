#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
int n, m;
int a[1002][1002] = {0};
int f[1002][1002] = {0};
vector<int> res;
int startpos = 0;

void ReadData()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
}

void MakeF()
{
    for (int j = 1; j <= m; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            f[i][j] = max(f[i - 1][j - 1], max(f[i][j - 1], f[i + 1][j - 1])) + a[i][j];
        }
    }
}

int maxIndex(int x, int y, int z, int col)
{
    int maxVal = 0, maxID = 0;
    for (int i = x; i <= z; ++i)
    {
        if (f[i][col] > maxVal)
        {
            maxVal = f[i][col];
            maxID = i;
        }
    }
    return maxID;
}

void TraceBack(int index, int col)
{
    if (col == 1){
        startpos = index;
        return;
    }
    int id = maxIndex(index - 1, index, index + 1, col - 1);
    TraceBack(id, col - 1);
    res.push_back(id - index + 1);
}

void Solve()
{
    int ans = 0;
    int index = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (f[i][m] > ans)
        {
            ans = f[i][m];
            index = i;
        }
    }
    TraceBack(index, m);
    cout << startpos << " " << ans << endl;
    string lookup = "DFU";
    for (int i = 0, len = res.size(); i < len; ++i)
        cout << lookup[res[i]];
}

int main()
{
    freopen("race.inp", "r", stdin);
    freopen("race.out", "w", stdout);

    ReadData();
    MakeF();
    Solve();

    return 0;
}
