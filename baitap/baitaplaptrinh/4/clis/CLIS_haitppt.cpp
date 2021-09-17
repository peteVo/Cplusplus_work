#include <iostream>
#include <cstdio>

using namespace std;
#define maxN 100000

int a[2*maxN+1], n;

void ReadData()
{
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        cin>>a[i];
        a[i+n] = a[i];
    }
}

void Solve()
{
    int i = 1, lmax = 0, lo, hi;
    while (i <= n)
    {
        int j = i+1;
        while (j - i + 1 <= 2*n && a[j] >= a[j-1])
        {
            if (j - i + 1 > lmax)
            {
                lmax = j-i+1;
                hi = j;
                lo = j - lmax + 1;
            }
            ++j;
        }
        i = j;
    }
    lo = (lo-1) % n + 1;
    hi = (hi-1) % n + 1;
    cout<<lo<<" "<<hi;
}

int main()
{
    freopen("CLIS.INP", "r", stdin);
    freopen("CLIS.OUT", "w", stdout);
    ReadData();
    Solve();
    return 0;
}
