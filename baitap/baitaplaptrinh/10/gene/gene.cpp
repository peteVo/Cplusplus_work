#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
int avg;
string s;
int p[4][1000001] = {0};
int total[4] = {0};

int decode(char c)
{
    if(c == 'A') return 0;
    if(c == 'T') return 1;
    if(c == 'G') return 2;
    return 3; // if(c == 'C') return 3;
}

void ReadData()
{
    cin >> n >> s;
    avg = n/4;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 4; ++j){
            p[j][i] = p[j][i-1];
        }
        int d = decode(s[i-1]);
        total[d]++;
        p[d][i]++;
    }
}

bool valid(int i, int j)
{
    for(int k = 0; k < 4; ++k){
        if(total[k] - (p[k][j] - p[k][i-1]) > avg) return false;
    }
    return true;
}

int Solve()
{
    if(total[0] == avg && total[1] == avg && total[2] == avg && total[3] == avg) return 0;

    int minlen = n+1;

    int i = 1, j = 1;
    while(i <= j && j <= n){
        if(valid(i, j)){
            minlen = min(minlen, j-i+1);
            i++;
        }
        else j++;
    }
    return minlen;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("gene.inp", "r", stdin);
    freopen("gene.out", "w", stdout);

    ReadData();
    cout << Solve() << "\n";

    return 0;
}
