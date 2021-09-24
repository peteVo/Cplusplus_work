#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

int n;
ll x;
map<ll, int> a;

void ReadData()
{
    cin >> n;
    ll temp;
    for(int i = 1; i <= n; ++i){
        cin >> temp;
        a[temp]++;
    }
    cin >> x;
}

ll Solve()
{
    int cnt = 0;
    for(map<ll, int>::iterator it = a.begin(); it != a.end(); ++it){
        if(a.find(x - it->first) != a.end()) cnt = cnt + it->second * a[x - it->first];
    }
    return cnt/2;
}

int main()
{
    freopen("sumx.inp","r",stdin);
    freopen("sumx.out","w",stdout);
    ReadData();
    cout << Solve();
    return 0;
}
