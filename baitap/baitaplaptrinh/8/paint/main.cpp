#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
int houses[21][4];

void ReadData()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 3; ++j)
            cin >> houses[i][j];
    }
}

int MinMoney(int i, int j)
{
    if (i == 1)
        return houses[i][j];
    int x, y;
    if (j == 1)
        x = 2, y = 3;
    else if (j == 2)
        x = 1, y = 3;
    else if (j == 3)
        x = 1, y = 2;
    return min(MinMoney(i - 1, x), MinMoney(i - 1, y)) + houses[i][j];
}

int Solve()
{
    return min(MinMoney(n, 1), min(MinMoney(n, 2), MinMoney(n, 3)));
}

int main()
{
    freopen("paint.inp", "r", stdin);
    freopen("paint.out", "w", stdout);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        ReadData();
        cout << Solve() << endl;
    }

    return 0;
}
