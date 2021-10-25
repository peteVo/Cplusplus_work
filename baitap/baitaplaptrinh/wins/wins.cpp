#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct Point {
    int x, y;
};
struct Window{
    Point a, b;
    int index;
}windows[1001];
int n;
Point ClosePoint;

stack<Window> stak;

bool isBlocking(Window w)
{
    return w.a.x <= ClosePoint.x &&
           w.a.y <= ClosePoint.y &&
           w.b.x >= ClosePoint.x &&
           w.b.y >= ClosePoint.y;
}

void ReadData()
{
    cin >> n;

    cin >> windows[1].a.x >> windows[1].a.y >> windows[1].b.x >> windows[1].b.y;
    ClosePoint.x = windows[1].b.x, ClosePoint.y = windows[1].a.y;
    windows[1].index = 1;
    stak.push(windows[1]);

    for(int i = 2; i <= n; ++i){
        cin >> windows[i].a.x >> windows[i].a.y >> windows[i].b.x >> windows[i].b.y;
        windows[i].index = i;
        
        if(isBlocking(windows[i])) stak.push(windows[i]);
    }
}

void Solve()
{
    cout << stak.size() << endl;
    while(!stak.empty()){
        cout << stak.top().index << " ";
        stak.pop();
    }
    cout << endl;
}

int main()
{
    freopen("wins.inp", "r", stdin);
    freopen("wins.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
