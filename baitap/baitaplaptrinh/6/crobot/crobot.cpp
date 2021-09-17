#include <iostream>
#include <cstdio>

using namespace std;

/*
struct Point
{
    int x,y;
}facings[4];

Point EndPoint(string s, int n)
{
    facings[0].x = 0, facings[0].y = 1;
    facings[1].x = 1, facings[1].y = 0;
    facings[2].x = 0, facings[2].y = -1;
    facings[3].x = -1, facings[3].y = 0;

    int facingIndex = 0;
    Point pos;
    pos.x = 0, pos.y = 0;
    for(int i = 0; i < n; ++i){
        switch(s[i]){
            case 'R':
                facingIndex = facingIndex == 3 ? 0 : facingIndex + 1;
                pos.x +=facings[facingIndex].x;
                pos.y += facings[facingIndex].y;
                break;
            case 'L':
                facingIndex = facingIndex == 0 ? 3 : facingIndex - 1;
                pos.x +=facings[facingIndex].x;
                pos.y += facings[facingIndex].y;
                break;
            case 'G':
                pos.x +=facings[facingIndex].x;
                pos.y += facings[facingIndex].y;
                break;
            case 'B':
                pos.x -=facings[facingIndex].x;
                pos.y -= facings[facingIndex].y;
                break;
        }
    }
    return pos;
}
*/

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void EndPoint(int n, string s)
{
    int direction = 1;
    int x = 0, y = 0;
    for(int i = 0; i < n; ++i){
        switch(s[i])
        {
            case 'G':
                x += dx[direction];
                y += dy[direction];
                break;
            case 'L':
                direction = (direction - 1 + 4) % 4;
                x += dx[direction];
                y += dy[direction];
                break;
            case 'R':
                direction = (direction + 1) % 4;
                x += dx[direction];
                y += dy[direction];
                break;
            case 'B':
                direction = (direction + 2) % 4;
                x += dx[direction];
                y += dy[direction];
                break;
        }
    }
    cout << x << " " << y;
}

int main()
{
    freopen("crobot.inp", "r", stdin);
    freopen("crobot.out", "w", stdout);

    /*
    int n;
    cin >> n;
    string s;
    cin >> s;

    Point ans = EndPoint(s, n);
    cout << ans.x << " " << ans.y;
    */

    int n;
    string s;
    cin >> n;
    cin >> s;

    EndPoint(n, s);

    return 0;
}
