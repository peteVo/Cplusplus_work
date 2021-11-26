#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct Dinosaur
{
    int w, s;
    int index;
} dino[1001];
int m;
int L[1001] = {0};
int Prev[1001] = {0};
vector<int> ans;

bool sorter(Dinosaur a, Dinosaur b)
{
    return a.s > b.s || (a.s == b.s && a.w < b.w);
}

void ReadData()
{
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> dino[i].w >> dino[i].s;
        dino[i].index = i;
    }
    sort(dino + 1, dino + 1 + m, sorter);
    //for (int i = 1; i <= m; ++i)
    //{
    //    cout << dino[i].w << " " << dino[i].s << endl;
    //}
}

void Solve()
{
    L[0] = 0;
    int len = 0;
    int maxID = 0;
    for(int i = 1; i <= m; ++i){
        maxID = 0;
        for(int j = 1; j <= i-1; ++j){
            if(dino[j].w < dino[i].w && L[j] > L[maxID]){
                maxID = j;
            }
        }
        L[i] = L[maxID] + 1;
        Prev[i] = maxID;
        len = max(len, L[i]);
    }

    maxID = 1;
    for(int i = 2; i <= m; ++i){
        if(L[i] > L[maxID]) maxID = i;
    }
    while(maxID > 0){
        ans.push_back(maxID);
        maxID = Prev[maxID];
    }

    cout << len << endl;
    for(int i = ans.size()-1; i >= 0; --i) cout << dino[ans[i]].index << " ";
    ///for(int i = ans.size()-1; i >= 0; --i) cout << dino[ans[i]].w << " " << dino[ans[i]].s << endl;
}

int main()
{
    freopen("dinosaur.inp", "r", stdin);
    freopen("dinosaur.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
