#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

char flagMat[7][10];
//int m, n, a[10][10];

void ReadData()
{
    for(int i = 1; i <= 6; ++i){
        string s;
        cin >> s;
        for(int j = 1; j <= 9; ++j){
            flagMat[i][j] = s[j-1];
        }
    }
}

int minDist(int x, int y, int z)
{
    int cntHor = 0;
    int cntVert = 0;

    //////////////////////////////Horizontal//////////////////////////////
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 9; ++j){
            if((int)flagMat[i][j] != x) cntHor++;
        }
    }
    for(int i = 2; i < 4; ++i){
        for(int j = 0; j < 9; ++j){
            if((int)flagMat[i][j] != y) cntHor++;
        }
    }
    for(int i = 4; i < 6; ++i){
        for(int j = 0; j < 9; ++j){
            if((int)flagMat[i][j] != z) cntHor++;
        }
    }
    ////////////////////////End of Horizontal////////////////////////////

    ///////////////////////////Vertical//////////////////////////////
    for(int j = 0; j < 3; ++j){
        for(int i = 0; i < 6; ++i){
            if((int)flagMat[i][j] != x) cntVert++;
        }
    }
    for(int j = 3; j < 6; ++j){
        for(int i = 0; i < 6; ++i){
            if((int)flagMat[i][j] != y) cntVert++;
        }
    }
    for(int j = 6; j < 9; ++j){
        for(int i = 0; i < 6; ++i){
            if((int)flagMat[i][j] != z) cntVert++;
        }
    }
    /////////////////////////End of vertical//////////////////////////////

    return min(cntHor, cntVert);
}

int Solve()
{
    int ans = 55;
    for(int i = 'A'; i <= 'Z'; ++i){
        for(int j = 'A'; j <= 'Z'; ++j){
            for(int k = 'A'; k <= 'Z'; ++k){
                if(j==i || j==k) continue;
                else ans = min(ans, minDist(i, j, k));
            }
        }
    }
    return ans;
}

int main()
{
    freopen("flag.inp", "r", stdin);
    freopen("flag.out", "w", stdout);

    ReadData();
    //Debug();
    //cout << Solve();
    cout << minDist('Z', 'A', 'M');

    return 0;
}
