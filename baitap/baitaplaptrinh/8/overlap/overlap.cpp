#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct pii
{
    int x, y;
    int index;
};

int n;
pii d[1001];
int Prev[1001] = {0};
int L[1001] = {0};

bool sorter(pii a, pii b)
{
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}
void ReadData()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i].x >> d[i].y;
        d[i].index = i;
    }
    sort(d + 1, d + 1 + n, sorter);
}

void Solve()
{
    vector<int> ans;
    L[0] = 0;
    int maxID = 0;
    for (int i = 1; i <= n; ++i)
    {
        maxID = 0;
        for (int j = 1; j <= i-1; ++j)
        {
            if (d[j].y == d[i].x && L[j] > L[maxID])
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
        ans.push_back(d[maxID].index);
        maxID = Prev[maxID];
    }
    cout << ans.size() << endl;
    for (int i = ans.size()-1; i >= 0; --i)
        cout << ans[i]<< endl;
}

int main()
{
    freopen("overlap.inp", "r", stdin);
    freopen("overlap.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
