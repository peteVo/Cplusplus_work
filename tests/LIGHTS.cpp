#include <bits/stdc++.h>

#define maxn 3000001
#define fori(a, b) for(int i = a; i<b; ++i)
#define forj(a, b) for(int j = a; j<b; ++j)

using namespace std;

long long n, m, a[600], x[maxn], y[maxn], X[maxn], Y[maxn], d1[maxn], d2[maxn], l1, l2, kq;
map<long long, long long> tk;

void SubSetGenX()
{
    int c2 = 0;
    forj(0, l1)
    {
        long long val = 0, dem = 0;
        fori(0, n/2)
            if ((j>>i) & 1)
            {
                val = val ^ x[i];
                ++dem;
            }
        d1[val] = dem;
        X[c2++] = val;
    }
}

void SubSetGenY()
{
    int c2 = 0;
    forj(0, l2)
    {
        long long val = 0, dem = 0;
        fori(0, n-n/2)
            if ((j>>i) & 1)
            {
                val = val ^ y[i];
                ++dem;
            }
        d2[val] = dem;
        Y[c2++] = val;
    }
    fori(0, c2) tk[Y[i]] = Y[i];
}

void SetUp()
{
    cin>>n>>m;
    long long j = 0, u, v;
    l1 = 1 << n/2; l2 = (1 << n-n/2);
    fori(0, n) a[i] = 1 << i;
    fori(1, m+1)
    {
        cin>>u>>v; --u; --v;
        a[u] = a[u] | (1 << v);
        a[v] = a[v] | (1 << u);
    }
    fori(0, n/2) x[i] = a[i];
    fori(n/2, n)
    {
        y[j++] = a[i];
    }
}

void Solve()
{
    SubSetGenX();
    SubSetGenY();
    fori(0, l1)
    {
        long long k = X[i] ^ ((1<<n) - 1);
        if (tk[k])
        {
            cout<<d1[X[i]] + d2[k];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("LIGHTS.INP","r",stdin);
    freopen("LIGHTS.OUT","w",stdout);
    SetUp();
    Solve();
    return 0;
}
