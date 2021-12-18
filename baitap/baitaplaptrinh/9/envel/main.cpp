#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct pt{
    int x, y;
    pt()
    {}
    pt(int a, int b){
        x = a, y = b;
    }
public:
    bool operator!=(pt a)
    {
        return x != a.x || y != a.y;
    }
}a[1000001];

int n = 0;
int x_max = -1, x_min = 1e9;
int y_max = -1, y_min = 1e9;
int x_plus_y_max = -1, x_plus_y_min = 1e9;
int x_minus_y_max = -1, x_minus_y_min = 1e9;

void Solve()
{
    int x, y;
    while(cin >> x && cin >> y){
        a[n+1].x = x, a[n+1].y = y;
        n++;

        x_max = max(x_max, x), x_min = min(x_min, x);
        y_max = max(y_max, y), y_min = min(y_min, y);
        x_plus_y_max = max(x_plus_y_max, x + y), x_plus_y_min = min(x_plus_y_min, x + y);
        x_minus_y_max = max(x_minus_y_max, x - y), x_minus_y_min = min(x_minus_y_min, x - y);
    }

    pt l1_l2(x_plus_y_max - y_max, y_max);
    pt l2_l3(x_max, x_plus_y_max - x_max);
    pt l3_l4(x_max, x_max - x_minus_y_max);
    pt l4_l5(x_minus_y_max + y_min, y_min);
    pt l5_l6(x_plus_y_min - y_min, y_min);
    pt l6_l7(x_min, x_plus_y_min - x_min);
    pt l7_l8(x_min, x_min - x_minus_y_min);
    pt l8_l1(x_minus_y_min + y_max, y_max);

    cout << l8_l1.x << " " << l8_l1.y << endl;
    if(l7_l8 != l8_l1) cout << l7_l8.x << " " << l7_l8.y << endl;
    if(l6_l7 != l7_l8) cout << l6_l7.x << " " << l6_l7.y << endl;
    if(l5_l6 != l6_l7) cout << l5_l6.x << " " << l5_l6.y << endl;
    if(l4_l5 != l5_l6) cout << l4_l5.x << " " << l4_l5.y << endl;
    if(l3_l4 != l4_l5) cout << l3_l4.x << " " << l3_l4.y << endl;
    if(l2_l3 != l3_l4) cout << l2_l3.x << " " << l2_l3.y << endl;
    if(l1_l2 != l2_l3 && l1_l2 != l8_l1) cout << l1_l2.x << " " << l1_l2.y << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("envel.inp", "r", stdin);
    freopen("envel.out", "w", stdout);

    Solve();

    return 0;
}
