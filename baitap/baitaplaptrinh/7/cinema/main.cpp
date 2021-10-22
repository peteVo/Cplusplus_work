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
ll sumA = 0;

void ReadData()
{
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> films[i].a >> films[i].b >> films[i].c, films[i].index = i, sumA += films[i].a;
}

bool sorter1(Film x, Film y)
{
    return x.b + y.a > y.b + x.a;
}

bool sorter2(Film x, Film y)
{
    return x.c + y.a > y.c + x.a;
}

bool sorter3(Film x, Film y)
{
    return x.b + x.c + y.a > y.b + y.c + x.a;
}

void Solve()
{
    //ll sumA = 0;
    //for(ll i = 1; i <= n; ++i) sumA += a[i];
    sort(films + 1, films + 1 + n, sorter1);
    Film winner11 = films[1];
    Film winner12 = films[2];

    sort(films + 1, films + 1 + n, sorter2);
    Film winner21 = films[1];
    Film winner22 = films[2];

    if(winner11.index == winner21.index){
        ll ans1 = winner12.b + winner21.c + sumA - winner12.a - winner21.a;
        ll ans2 = winner11.b + winner22.c + sumA - winner11.a - winner22.a;
        if(ans1 >= ans2){
            cout << ans1 << endl;
            cout << winner12.index << " " << winner21.index << endl;
        }
        else{
            cout << ans2 << endl;
            cout << winner11.index << " " << winner22.index << endl;
        }
    }
    else{
        cout << winner11.b + winner21.c + sumA - winner11.a - winner21.a << endl;
        cout << winner11.index << " " << winner21.index << endl;
    }
}

int main()
{
    freopen("cinema.inp", "r", stdin);
    freopen("cinema.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
