#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int n;
string a[100001];

bool cmp(string x, string y)
{
    string s1 = x + y;
    string s2 = y + x;
    return (s1 > s2);
}

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
}

void MaxNum()
{
    for(int i = 1; i <= n; ++i){
        cout << a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("maxnum.inp", "r", stdin);
    freopen("maxnum.out", "w", stdout);

    ReadData();
    MaxNum();

    return 0;
}
