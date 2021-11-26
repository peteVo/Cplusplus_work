#include <bits/stdc++.h>

using namespace std;

int n;
typedef pair<int, int> pii;
pii dominoes[100001];
map<int, int> tree;

bool sapxep(pii a, pii b)
{
    return (a.second < b.second ||
            (a.second == b.second && a.first < b.first));
}

void ReadData()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> dominoes[i].first >> dominoes[i].second;
    }
    sort(dominoes + 1, dominoes + 1 + n, sapxep);
}

int Solve()
{
    for (int i = 1; i <= n; ++i)
    {
        tree[dominoes[i].second] = max(tree[dominoes[i].second], tree[dominoes[i].first] + 1);
    }
    int maxlen = -1;
    for (map<int, int>::iterator it = tree.begin(); it != tree.end(); ++it)
    {
        maxlen = max(maxlen, it->second);
    }
    return maxlen;
}

int main()
{
    freopen("dominoes.inp", "r", stdin);
    freopen("dominoes.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
