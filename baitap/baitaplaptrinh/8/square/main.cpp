#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n, m;
int a[1001][1001];
int b[1001][1001];
//int s[1001][1001] = {0};

void ReadData()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
    {
        string temp;
        cin >> temp;
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] = int(temp[j - 1] == '*');
        }
    }
    //for (int i = 1; i <= m; ++i)
    //{
    //    for (int j = 0; j < n; ++j)
    //    {
    //        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    //    }
    //}
}

int Solve()
{
    int ans = 1;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] == 0)
                b[i][j] = 0;
            else
                b[i][j] = min(b[i][j - 1], min(b[i - 1][j], b[i - 1][j - 1])) + a[i][j];
            ans = max(ans, b[i][j]);
        }
    }
    return ans;
}

int main()
{
    freopen("square.inp", "r", stdin);
    freopen("square.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
