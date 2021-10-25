#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct Window{
    int x1, y1, x2, y2;
}windows[1001];
int n;

bool overlap[1001][1001] = {false}; // overlap[i][j] = true if window j overlap window i's close button
stack<int> stak;
int ans = 0;

void ReadData()
{
    cin >> n;

    for(int i = 1; i <= n; ++i){
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

void MakeOverlapMatrix() // Make the matrix that its value are such that
                         //overlap[i][j] = true if window j overlap window i's close button
{
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(isOverlap(windows[i], windows[j])) overlap[i][j] = true;
        }
    }
}

void MakeRowFalse(int j)
{
    for(int i = 1; i <= n; ++i) overlap[i][j] = false;
}

void Solve(int i)
{
    for(int j = 1; j <= n; ++j){
        if(overlap[i][j]){
            MakeRowFalse(j);
            ans++;
            stak.push(j);
            Solve(j);
        }
    }
}

int main()
{
    freopen("wins.inp", "r", stdin);
    freopen("wins.out", "w", stdout);

    ReadData();
    MakeOverlapMatrix();
    Solve(1);
    cout << ans << endl;
    while(!stak.empty()){
        cout << stak.top() << " ";
        stak.pop();
    }

    return 0;
}
