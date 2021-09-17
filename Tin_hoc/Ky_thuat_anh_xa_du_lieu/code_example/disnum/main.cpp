#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
map<int, int> a;

void ReadData()
{
    cin >> n;
    int x;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        ++a[x];
    }
}

int Solve()
{
    int cnt = 0;
    for(map<int, int>::iterator it = a.begin(); it != a.end(); ++it){
        cnt++;
    }
    return cnt;
}

int main()
{
    freopen("disnum.inp", "r", stdin);
    freopen("disnum.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
