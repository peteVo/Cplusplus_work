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

int distVert(char x, char y, char z)
{
    int cnt = 0;
    char c;
    //doc
    for(int i = 1; i <= 6; ++i){
        for(int j = 1; j <= 9; ++j){
            if(i <= 3) c=x;
            else if(i <= 6) c=y;
            else c=z;
            if(flagMat[i][j]!=c) cnt++;
        }
    }
    return cnt;
}

int distHor(char x, char y, char z)
{
    int cnt = 0;
    char c;
    //ngang
    for(int i = 1; i <= 6; ++i){
        for(int j = 1; j <= 9; ++j){
            if(i <= 2) c=x;
            else if(i <= 4) c=y;
            else c=z;
            if(flagMat[i][j]!=c) cnt++;
        }
    }
    return cnt;
}

int Solve()
{
    int ans = 55;
    for(char i = 'A'; i <= 'Z'; ++i){
        for(char j = 'A'; j <= 'Z'; ++j){
            for(char k = 'A'; k <= 'Z'; ++k){
                if(j!=i && j!=k)
                    ans = min(ans, min(distHor(i, j, k), distVert(i, j, k)));
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
    cout << Solve();
    //cout << minDist('Z', 'A', 'M');

    return 0;
}
