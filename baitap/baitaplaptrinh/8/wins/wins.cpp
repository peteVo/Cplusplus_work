#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct Window
{
    int x1, y1, x2, y2;
} windows[1001];
int n;
bool closed[1001] = {false};

stack<int> stak;
int ans = 0;

void ReadData()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> windows[i].x1 >> windows[i].y1 >> windows[i].x2 >> windows[i].y2;
    }
}

bool isOverlap(Window a, Window b) // Return true if window b overlaps a's close button
{
    return b.x1 <= a.x2 &&
           b.x2 >= a.x2 &&
           b.y1 <= a.y1 &&
           b.y2 >= a.y1;
}

void Solve(int i)
{
    for (int j = i; j <= n; ++j)
    {
        if (isOverlap(windows[i], windows[j]) && !closed[j])
        {
            ans++;
            stak.push(j);
            closed[j] = true;
            Solve(j);
        }
    }
}

int main()
{
    freopen("wins.inp", "r", stdin);
    freopen("wins.out", "w", stdout);

    ReadData();
    Solve(1);
    cout << ans << endl;
    while (!stak.empty())
    {
        cout << stak.top() << " ";
        stak.pop();
    }
    //Debug();

    return 0;
}
