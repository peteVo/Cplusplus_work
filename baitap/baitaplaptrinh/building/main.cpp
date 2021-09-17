#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int m, n;

int h[1001][1001];

int maxW[1001][1001] = {0}, maxN[1001][1001] = {0}, maxE[1001][1001] = {0}, maxS[1001][1001] = {0};

void ReadData()
{
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> h[i][j];
        }
    }
}

void MakeMaxArrays()
{
    for(int j = 0; j < n; ++j){
        for(int i = 0; i < m; ++i){
            if(j==0) maxW[i][j]=h[i][j];
            else maxW[i][j] = max(maxW[i][j-1], h[i][j]);
        }
    }
    for(int j = n-1; j > 0; --j){
        for(int i = 0; i < m; ++i){
            if(j==n-1) maxW[i][j]=h[i][j];
            else maxW[i][j] = max(maxE[i][j+1], h[i][j]);
        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(i==0) maxN[i][j]=h[i][j];
            else maxN[i][j] = max(maxN[i-1][j], h[i][j]);
        }
    }
    for(int i = m-1; i > 0; --i){
        for(int j = 0; j < n; ++j){
            if(i==m-1) maxN[i][j]=h[i][j];
            else maxN[i][j] = max(maxN[i+1][j], h[i][j]);
        }
    }
}

int main()
{
    freopen("building.inp", "r", stdin);
    freopen("")
    return 0;
}
