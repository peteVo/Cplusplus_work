#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

int m, n;
ll a[1002][1002] = {0};
ll s[1002][1002] = {0};

void ReadData()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
}

void MakeS()
{
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            s[i][j] = max(s[i - 1][j], s[i][j - 1]) + (a[i][j] % 2 == 0 ? a[i][j] : 0);
        }
    }
    /*
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    */
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("maxsum.inp", "r", stdin);
    freopen("maxsum.out", "w", stdout);

    ReadData();
    MakeS();
    cout << s[m][n];

    return 0;
}
