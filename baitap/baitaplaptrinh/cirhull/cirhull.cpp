#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>

using namespace std;
typedef pair<double, double> pii;

int n;
pii a[101];

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

void Solve()
{
    double r_max = 1e18;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            double m = 0;
            pii mid_point = pii((a[i].first + a[j].first) / 2, (a[i].second + a[j].second) / 2);
            for(int k = 1; k <= n; ++k){
                m = max(m, sqrt((mid_point.first - a[k].first) * (mid_point.first - a[k].first) +
                                    (mid_point.second - a[k].second) * (mid_point.second - a[k].second)));
            }
            r_max = min(r_max, m);
        }
    }
    for(int i = 1; i <= n; ++i){
        double m = 0;
        for(int j = 1; j <= n; ++j){
            m = max(m, sqrt((a[i].first - a[j].first) * (a[i].first - a[j].first) +
                                    (a[i].second - a[j].second) * (a[i].second - a[j].second)));
            //cout << "p1: " << a[i].first << " " << a[i].second << ", p2: " << a[j].first << " " << a[j].second << " -> d: "
            //<< sqrt((a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second))/2 << endl;
        }
        r_max = min(r_max, m);
    }
    cout << fixed << setprecision(6) << r_max;
    return;
}

int main()
{
    freopen("cirhull.inp", "r", stdin);
    freopen("cirhull.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
