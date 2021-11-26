#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll a[51] = {0};

void CreateAnswerArray()
{
    a[1] = 1, a[2] = 3;
    for (int i = 3; i <= 50; ++i)
    {
        a[i] = a[i - 1] + 2 * a[i - 2];
    }
}

int main()
{
    freopen("tiling.inp", "r", stdin);
    freopen("tiling.out", "w", stdout);

    CreateAnswerArray();
    ll n;
    while (cin >> n)
    {
        cout << a[n] << endl;
    }

    return 0;
}
