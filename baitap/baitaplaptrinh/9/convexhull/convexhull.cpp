#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>

using namespace std;

struct pt // The point struct
{
    double x, y;
    pt(){}
    pt(int a, int b){x = a, y = b;}
};

int n;
pt p[100001];
pt up[100001], down[100001];
pt ans[100001];

bool cmp(pt a, pt b) // Checks a.x < b.x or if they're equal -> check a.y < b.y
{
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

double Area(pt a, pt b, pt c)
{
    return ((b.x - a.x)*(b.y + a.y) + (c.x - b.x)*(c.y + b.y) + (a.x - c.x)*(a.y + c.y))/2;
}

void ReadData()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
    sort(p, p + n, cmp);
}

void Solve()
{
    int len1 = 2, len2 = 2;
    up[0] = p[0], up[1] = p[1];
    down[0] = p[n-1], down[1] = p[n-2];

    for(int i = 2; i < n;){
        double S = Area(up[len1-2], up[len1-1], p[i]);
        if(S <= 0) len1--;
        if(len1 < 2 || S > 0) up[len1++] = p[i++];
    }
    for(int i = n - 3; i >= 0;){
        double S = Area(down[len2-2], down[len2-1], p[i]);
        if(S <= 0) len2--;
        if(len2 < 2 || S > 0) down[len2++] = p[i--];
    }

    int len = 0;
    for(int i = 1; i < len1 - 1; ++i){
        ans[len++] = up[i];
    }
    for(int i = 0; i < len2; ++i){
        ans[len++] = down[i];
    }

    double area = 0;
    for(int i = 0; i < len; ++i){
        area = area + (ans[(i+1)%len].x - ans[i].x)*(ans[(i+1)%len].y + ans[i].y) / 2.0;
    }
    area = area;
    cout << len << endl << fixed << setprecision(1) << area << endl << setprecision(0);

    for(int i = len-1; i >= 0; --i){
        cout << ans[i].x << " " << ans[i].y << endl;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("convexhull.inp", "r", stdin);
    freopen("convexhull.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
