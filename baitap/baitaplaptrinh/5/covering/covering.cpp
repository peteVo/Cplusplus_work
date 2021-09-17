#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;

struct Point
{
    ll x, y;
}points[1000001];

bool tang(Point a, Point b)
{
    return(a.x < b.x);
}

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> points[i].x >> points[i].y;
        points[i].x /= 2, points[i].y /= 2;
    }

    sort(points + 1, points + 1 + n, tang);
}

ll CoverArea()
{
    ll s = 0;

    for(int i = n; i >= 1; --i){
        if(points[i - 1].y < points[i].y) points[i - 1].y = points[i].y;

        s = s + points[i].y * (points[i].x - points[i - 1].x);
    }

    return s * 4;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("covering.inp","r",stdin);
    freopen("covering.out","w",stdout);

    ReadData();

    cout << CoverArea();

    return 0;
}
