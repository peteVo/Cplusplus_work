#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Film
{
    ll a, b, c;
    ll index;
} films[100001];

ll n;

void ReadData()
{
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> films[i].a >> films[i].b >> films[i].c, films[i].index = i;
}

bool sorter1(Film x, Film y)
{
    return x.b + y.a > y.b + x.a;
}

bool sorter2(Film x, Film y)
{
    return x.c + y.a > y.c + x.a;
}

void Solve()
{
    //ll sumA = 0;
    //for(ll i = 1; i <= n; ++i) sumA += a[i];
    sort(films + 1, films + 1 + n, sorter1);
    Film winner1 = films[1];

    sort(films + 1, films + 1 + n, sorter2);
    Film winner2 = films[1];

    ll ans = winner1.b + winner2.c;
    for(ll i = 1; i <= n; ++i){
        if(films[i].index != winner1.index && films[i].index != winner2.index){
            ans += films[i].a;
        }
    }

    cout << ans << endl;
    cout << winner1.index << " " << winner2.index << endl;
}

int main()
{
    freopen("cinema.inp", "r", stdin);
    freopen("cinema.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
