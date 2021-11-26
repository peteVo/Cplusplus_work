#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int n;
int a[202][102] = {0};
int f[202][102] = {0};

void ReadData()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = n + 1, m = 2 * n - 1; i <= m; ++i)
    {
        for (int j = 1, x = 2 * n - i; j <= x; ++j)
        {
            cin >> a[i][j];
        }
    }
}

void MakeF()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
        }
    }
    for (int i = n + 1, m = 2 * n - 1; i <= m; ++i)
    {
        for (int j = 1, x = 2 * n - i; j <= x; ++j)
        {
            f[i][j] = max(f[i - 1][j], f[i - 1][j + 1]) + a[i][j];
        }
    }
    /*
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = n + 1, m = 2 * n - 1; i <= m; ++i)
    {
        for (int j = 1, x = 2 * n - i; j <= x; ++j)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    */
}

int Solve()
{
    return f[2 * n - 1][1];
}

int main()
{
    freopen("bananas.inp", "r", stdin);
    freopen("bananas.out", "w", stdout);

    int T;
    cin >> T;
    for(int i = 0; i < T; ++i){
        ReadData();
        MakeF();
        cout << Solve() << endl;
    }

    return 0;
}
