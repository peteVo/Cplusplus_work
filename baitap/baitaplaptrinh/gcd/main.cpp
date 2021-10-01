#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int n;
int a[100001];
int g[100001];

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    g[1] = a[1];
    for(int i = 2; i <= n; ++i) g[i] = __gcd(g[i-1], a[i]);
    //for(int i = 1; i <= n; ++i) cout << a[i] << endl;
}

int main()
{
    freopen("gcd.inp", "r", stdin);
    freopen("gcd.out", "w", stdout);

    ReadData();
    for(int i = 1; i <= n; ++i) cout << g[i] << endl;

    return 0;
}
