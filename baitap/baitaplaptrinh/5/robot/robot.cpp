#include <iostream>
#include <cstdio>

using namespace std;

int n;

struct Point
{
    int x,y;
}points[100001];

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> points[i].x >> points[i].y;
    }
}

bool isRightTurn(Point one, Point two, Point three)
{
    return((one.y < two.y && two.x < three.x) || (one.x < two.x && two.y > three.y)
           || (one.y > two.y && two.x > three.x) || (one.x > two.x && two.y < three.y));
}

int rightTurns()
{
    int cnt = 0;
    if(n < 3) return 0;
    for(int i = 3; i <= n; ++i){
        if(isRightTurn(points[i - 2], points[i - 1], points[i])) cnt++;
    }
    return cnt;
}

int main()
{
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);

    ReadData();
    //for(int i = 1; i <= n; ++i) cout << "points[" << i << "].x : " << points[i].x << " ---- points[" << i << "].y : " << points[i].y << endl;
    cout << rightTurns();



    return 0;
}
