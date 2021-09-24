#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int m, n;

//int maxN[1000][1000] = {0};
//int maxE[1000][1000] = {0};
//int maxW[1000][1000] = {0};
//int maxS[1000][1000] = {0};

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

/*void MakeNEWS()
{
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(j > 0) maxW[i][j] = max(a[i][j], maxW[i][j-1]);
            else maxW[i][j] = a[i][j];
            if(i > 0) maxN[i][j] = max(a[i][j], maxN[i-1][j]);
            else maxN[i][j] = a[i][j];
        }
    }
    for(int i = m-1; i >= 0; --i){
        for(int j = n-1; j >= 0; --j){
            if(j < n-1) maxE[i][j] = max(a[i][j], maxE[i][j+1]);
            else maxE[i][j] = a[i][j];
            if(i < m-1) maxS[i][j] = max(a[i][j], maxS[i+1][j]);
            else maxS[i][j] = a[i][j];
        }
    }
}

bool Valid(int i, int j)
{
    return(
       building[i][j] >= maxN[i][j] ||
       building[i][j] >= maxW[i][j] ||
       building[i][j] >= maxE[i][j] ||
       building[i][j] >= maxS[i][j]
    );
}

int HouseNotValid()
{
    int cnt = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(!Valid(i, j)) cnt++;
        }
    }
    return cnt;
}

void Debug()
{
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << maxN[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << maxE[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << maxW[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << maxS[i][j];
        }
        cout << endl;
    }
    cout << endl;
}*/

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
