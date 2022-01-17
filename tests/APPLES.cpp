#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define maxn 1000001
#define pb push_back
#define fori(a, b) for(int i = a; i<b; ++i)
#define forj(a, b) for(int j = a; j<b; ++j)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rs(a, n) a.resize(n)

using namespace std;

ll n, kq1, kq2;

struct pii
{
    ll x, y, id;
    double cot;
};
pii a[maxn];

bool cmp(pii a, pii b)
{
    return (a.y < b.y);
}

void Move()
{
    sort(a, a+n, cmp);
    kq1 = a[0].id;
    int movex = a[0].x, movey = a[0].y;
    fori(0, n)
    {
        a[i].x -= movex;
        a[i].y -= movey;
    }
}

bool cmp2(pii a, pii b)
{
    return (a.cot < b.cot);
}

void Solve()
{
    fori(1, n)
    {
        if (a[i].y == 0) a[i].cot = 1e7;
        else a[i].cot = (double)a[i].x / a[i].y;
    }
    sort(a+1, a+n, cmp2);
    kq2 = a[n/2].id;
    cout<<kq1<<' '<<kq2;
}

int main()
{
    fast;
    freopen("APPLES.INP", "r", stdin);
    freopen("APPLES.OUT", "w", stdout);
    cin>>n;
    fori(0, n)
    {
        cin>>a[i].x>>a[i].y;
        a[i].id = i+1;
    }
    Move();
    Solve();
    return 0;
}
