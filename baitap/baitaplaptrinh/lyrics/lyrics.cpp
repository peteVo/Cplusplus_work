#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n, m;
string lines[1001];

void ReadData()
{
    cin >> n >> m;
    string temp;
    getline(cin, temp);
    for (int i = 1; i <= n; ++i)
        getline(cin, lines[i]);
    //for (int i = 1; i <= n; ++i)
    //    cout << lines[i] << endl;
}

int Solve()
{
    int k = (int)1e4;
    for (int i = 1; i <= n - m; ++i)
    {
        int len1 = lines[i].length() - 1, len2 = lines[i + m].length() - 1;
        int cnt = 0;
        while (len1 >= 0 && len2 >= 0 && lines[i][len1] == lines[i + m][len2])
        {
            cnt++;
            len1--, len2--;
        }
        k = min(k, cnt);
    }
    return k;
}

int main()
{
    freopen("lyrics.inp", "r", stdin);
    freopen("lyrics.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
