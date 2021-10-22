#include <iostream>
#include <cstdio>
#define maxN 200

using namespace std;
int num[201][201];
int pow10[201];

string printAns(int x, int y)
{
    string ans = "";
    for(int i = 0; i < x; ++i){
        ans.append("8");
    }
    for(int j = 0; j < y; ++j){
        ans.append("6");
    }
    return ans;
}

string Solve(int X)
{
    int minLen = 1e6;
    int posI, posJ;
    pow10[0] = 0, pow10[1] = 1;
    for(int i = 2; i <= 200; ++i){
        pow10[i] = pow10[i-1] * 10 % X;
        //cout << pow10[i] << " ";
    }

    num[0][0] = 0;
    for(int i = 1; i <= 200; ++i) num[i][0] = (8 * pow10[i] + num[i - 1][0]) % X;
    for(int i = 1; i <= 200; ++i) num[0][i] = (num[0][i - 1] * 10 + 6) % X;
    for(int i = 1; i <= 200 - 1; ++i){
        for(int j = 1; j <= 200 - i; ++j){
            num[i][j] = (num[i][j - 1] * 10 + 6) % X;
        }
    }
    for(int i = 0; i <= 200; i++){
        for(int j = 0; j <= 200 - i; ++j){
            if(i == 0 && j == 0) continue;
            if(num[i][j] == 0){
                if(minLen > i + j){
                    minLen = i + j;
                    posI = i, posJ = j;
                }
            }
        }
    }
    if(minLen != 1e6){
        return printAns(posI, posJ);
    }
    else return "-1";
}

int main()
{
    freopen("num86.inp", "r", stdin);
    freopen("num86.out", "w", stdout);

    int T;
    cin >> T;
    for(int i = 0; i < T; ++i){
        int X;
        cin >> X;
        cout << Solve(X);
        cout << endl;
    }
    return 0;
}
