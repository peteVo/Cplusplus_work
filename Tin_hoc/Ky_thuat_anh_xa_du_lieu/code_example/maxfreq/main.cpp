#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int n;
map<int, int> a;

void ReadData()
{
    cin >> n;
    int x;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        a[x]++;
    }
}

int Solve()
{
    int M = -1;
    int ans = -1;
    for(map<int, int>::iterator it = a.begin(); it != a.end(); ++it){
        if(M < it->second){
            M = it->second;
            ans = it->first;
        }
    }
    return ans;
}

int main()
{
    freopen("maxfreq.inp","r",stdin);
    freopen("maxfreq.out","w",stdout);
    ReadData();
    cout << Solve();
    return 0;
}
