#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
const double INF = 1e18;

int n;

struct pt
{
    int x, y;
} p[101];

double distance(pt a, pt b)
{
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double areaOfTraingle(pt a, pt b, pt c)
{
    return abs(((b.x - a.x)*(b.y + a.y) + (c.x - b.x)*(c.y +b.y) + (a.x - c.x)*(a.y + c.y)) / 2.0);
}

bool acuteTriangle(pt a, pt b, pt c)
{
    double AB = distance(a, b), BC = distance(b, c), AC = distance(c, a);
    AB *= AB, BC *= BC, AC *= AC;
    if(AB < BC + AC && BC < AB + AC && AC < BC + AB) return true;
    return false;
}

double radiusOfCircle(pt a, pt b, pt c)
{
    double AB = distance(a, b), BC = distance(b, c), AC = distance(c, a);
    double r1 = AB * BC * AC / areaOfTraingle(a, b, c) / 4.0; // tam giac ABC nhon
    double r2 = max(AB, max(AC, BC)) / 2.0; // tam giac ABC tu
    if(acuteTriangle(a, b, c)) return r1;
    return r2;
}

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;
}

double Solve()
{
    double maxradius = -INF;
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            for(int k = j + 1; k <= n; ++k){
                maxradius = max(maxradius, radiusOfCircle(p[i], p[j], p[k]));
            }
        }
    }
    return maxradius;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cirhull.inp", "r", stdin);
    freopen("cirhull.out", "w", stdout);

    ReadData();
    cout << fixed << setprecision(6) << Solve();

    return 0;
}
