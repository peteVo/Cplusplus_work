#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int m, n;

int a[1000][1000];
bool b[1000][1000] = {false};

void ReadData()
{
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
}

void Update(int i, int j, int& hmax)
{
    if(a[i][j] >= hmax){
        hmax = a[i][j];
        b[i][j] = true;
    }
}

void MakeB()
{
    for(int i = 0; i < m; ++i){
        int hmax = 0;
        for(int j = 0; j < n; ++j) Update(i, j, hmax);

        hmax = 0;
        for(int j = n-1; j >= 0; --j) Update(i, j, hmax);
    }
    for(int j = 0; j < n; ++j){
        int hmax = 0;
        for(int i = 0; i < m; ++i) Update(i, j, hmax);

        hmax = 0;
        for(int i = m-1; i >= 0; --i) Update(i, j, hmax);
    }
}

int Solve()
{
    int cnt = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(!b[i][j]) cnt++;
        }
    }
    return cnt;
}

int main()
{
    freopen("building.inp", "r", stdin);
    freopen("building.out", "w", stdout);

    ReadData();
    MakeB();
    //MakeNEWS();
    //Debug();
    cout << Solve();

    return 0;
}
