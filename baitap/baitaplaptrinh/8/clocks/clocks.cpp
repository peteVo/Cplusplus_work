#include <iostream>
#include <cstdio>

using namespace std;

int a[10] = {0};
int tempA[10] = {0};
int T[10] = {0};
int savedT[10] = {0};
int ans = 1e8;

int mapping[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 1, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 1}};

void ReadData()
{
    for (int i = 1; i <= 9; ++i)
        cin >> a[i];
}

bool isValid()
{
    for (int i = 1; i <= 9; ++i)
    {
        tempA[i] = a[i];
        for (int j = 1; j <= 9; ++j)
        {
            tempA[i] += mapping[i][j] * T[j];
        }
        tempA[i] %= 4;
        if (tempA[i] != 0)
            return false;
    }
    return true;
}

void SaveResult()
{
    int sum = 0;
    for (int i = 1; i <= 9; ++i)
    {
        sum += T[i];
    }
    if (sum < ans)
    {
        ans = sum;
        for (int i = 1; i <= 9; ++i)
        {
            savedT[i] = T[i];
        }
    }
}

void Try(int index)
{
    for (int val = 0; val < 4; ++val)
    {
        T[index] = val;
        if (index == 9)
        {
            if (isValid())
                SaveResult();
        }
        else
            Try(index + 1);
    }
}

int main()
{
    freopen("clocks.inp", "r", stdin);
    freopen("clocks.out", "w", stdout);

    ReadData();
    Try(1);
    if (ans == (int)1e8)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        cout << ans << endl;
        for (int i = 1; i <= 9; ++i)
        {
            for (int j = 1; j <= savedT[i]; ++j)
            {
                cout << i << endl;
            }
        }
    }

    return 0;
}
