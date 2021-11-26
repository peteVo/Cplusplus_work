#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, m, k;
vector<int> xcut, ycut;

void ReadData()
{
    xcut.push_back(0), ycut.push_back(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; ++i){
        int x, y;
        cin >> x;
        if(x == 0){
            cin >> y;
            xcut.push_back(y);
        }
        else{
            cin >> y;
            ycut.push_back(y);
        }
    }
    xcut.push_back(n), ycut.push_back(m);
    sort(xcut.begin(), xcut.end());
    sort(ycut.begin(), ycut.end());
}

int Solve()
{
    int ansX = 0;
    for(int i = 1, len = xcut.size(); i < len; ++i){
        ansX = max(ansX, xcut[i] - xcut[i-1]);
    }
    int ansY = 0;
    for(int i = 1, len = ycut.size(); i < len; ++i){
        ansY = max(ansY, ycut[i] - ycut[i-1]);
    }
    return min(ansX, ansY);
}

int main()
{
    freopen("maxpiece.inp", "r", stdin);
    freopen("maxpiece.out", "w", stdout);

    ReadData();
    cout<< Solve();

    return 0;
}
