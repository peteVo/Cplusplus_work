#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int INF = 1e9;
int n;
int a[402][402] = {0};
int A[402][402] = {0}, B[402][402] = {0};

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
}

void Prep()
{
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            A[i][j] = A[i-1][j-1] + a[i][j];

    for(int i = 1; i <= n; ++i)
        for(int j = n; j >= 1; --j)
            B[i][j] = B[i-1][j+1] + a[i][j];

    /*for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << A[i][j] << " ";
        }
        cout << endl;
     }
     for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << B[i][j] << " ";
        }
        cout << endl;
     }*/
}

int Solve()
{
    int maxBeauty = -INF;
    for(int c = 1; c <= n; ++c){
        for(int i = 1; i + c - 1 <= n; ++i){
            for(int j = 1; j + c - 1 <= n; ++j){
                int beauty = A[i+c-1][j+c-1] - A[i-1][j-1] - B[i+c-1][j] + B[i-1][j+c];
                maxBeauty = max(maxBeauty, beauty);
            }
        }
    }
    return maxBeauty;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("matrix.inp", "r", stdin);
    freopen("matrix.out", "w", stdout);

    ReadData();
    Prep();
    cout << Solve();

    return 0;
}
