#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[200001];
vector<int> towers;

void ReadData()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
}

int Solve()
{
    for (int i = 1; i <= n; ++i)
    {
        vector<int>::iterator it_upp = upper_bound(towers.begin(), towers.end(), a[i]);
        if (it_upp != towers.end())
        {
            towers[it_upp - towers.begin()] = a[i];
        }
        else
        {
            towers.push_back(a[i]);
        }
    }
    //towers.erase(towers.begin());
    //for(int i = 0; i < towers.size(); ++i) cout << towers[i] << endl;
    return towers.size();
}

int main()
{
    freopen("towers.inp", "r", stdin);
    freopen("towers.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
