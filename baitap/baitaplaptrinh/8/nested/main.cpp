#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct window
{
    int x1, y1, x2, y2;
} a[101];
bool nest[101][101];
int n;
int L[101] = {0};
int Prev[101];

bool sorter(window t, window z)
{
    return (t.x2 - t.x1) * (t.y2 - t.y1) < (z.x2 - z.x1) * (z.y2 - z.y1);
}

void ReadData()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
    sort(a + 1, a + 1 + n, sorter);
}

bool isNested(window t, window z) // Return true only if window a nests window b
{
    return t.x1 <= z.x1 && t.y1 <= z.y1 &&
           t.x2 >= z.x2 && t.y2 >= z.y2;
}

void Solve()
{
    vector<int> ans;

    L[0] = 0;
    int maxID = 0;
    for (int i = 1; i <= n; ++i)
    {
        maxID = 0;
        for (int j = 1; j <= i - 1; ++j)
        {
            if (isNested(a[i], a[j]) && L[j] > L[maxID])
            {
                maxID = j;
            }
        }
        L[i] = L[maxID] + 1;
        Prev[i] = maxID;
    }

    maxID = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (L[i] > L[maxID])
            maxID = i;
    }
    while (maxID > 0)
    {
        ans.push_back(maxID);
        maxID = Prev[maxID];
    }
    cout << ans.size();
}

int main()
{
    freopen("nested.inp", "r", stdin);
    freopen("nested.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
