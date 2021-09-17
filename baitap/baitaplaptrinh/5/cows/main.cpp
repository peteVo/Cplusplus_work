#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, maxEatingCap = 0;

struct Cow
{
    ll t, d;
}cows[100001];

void ReadData()
{

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> cows[i].t >> cows[i].d;
        maxEatingCap += cows[i].d;
    }
}

bool sorter(Cow a, Cow b)
{
    return (a.d * b.t > b.d * a.t);
}

ll minFlowersEaten()
{
    sort(cows + 1, cows + 1 + n, sorter);
    ll cnt = 0;
    for(int i = 1; i <= n; ++i){
        maxEatingCap -= cows[i].d;
        cnt = cnt + maxEatingCap * cows[i].t * 2;
    }
    return cnt;
}

int main()
{
    freopen("cows.inp", "r", stdin);
    freopen("cows.out", "w", stdout);

    ReadData();

    cout << minFlowersEaten();

    return 0;
}
