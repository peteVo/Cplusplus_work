#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <queue>
#define maxN 1000000000

using namespace std;

vector<int> jnums;
int countn;

void BFS(int stop)
{
    queue<int> Q;
    for(int i = 1; i <= 9; ++i) Q.push(i);
    while(!Q.empty()){
        int val = Q.front();
        Q.pop();
        jnums.push_back(val);
        int dv[2] {val % 10 - 1, val % 10 + 1};
        for(int i = 0; i < 2; ++i)
        {
            if(dv[i] >= 0 && dv[i] <= 9){
                int val2 = val * 10 + dv[i];
                if(val2 <= stop) Q.push(val2);
            }
        }
    }
}

int main()
{
    freopen("jnum.inp", "r", stdin);
    freopen("jnum.out", "w", stdout);

    BFS(1000000000);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        int n;
        cin >> n;
        cout << 0 << " ";
        int j = 0;
        while(jnums[j] <= n) {cout << jnums[j] << " "; j++;}
        cout << endl;
    }

    return 0;
}
