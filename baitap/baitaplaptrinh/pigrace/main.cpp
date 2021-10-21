#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
typedef long long ll;
ll n;
map<ll, ll> a, loseA;
map<ll, ll> b, loseB;

void ReadData()
{
    // Read the input data
    cin >> n;
    for(int i = 1; i <= n; ++i){
        ll x;
        cin >> x;
        a[x]++;
    }
    for(int i = 1; i <= n; ++i){
        ll x;
        cin >> x;
        b[x]++;
    }
}

void MakeMaps()
{
    ll cnt = 0;
    for(map<ll, ll>::iterator it = a.begin(); it != a.end(); ++it){
        loseA[it->first] = cnt + it->second;
        cnt += it->second;
    }

    cnt = 0;
    for(map<ll, ll>::iterator it = b.begin(); it != b.end(); ++it){
        loseB[it->first] = cnt + it->second;
        cnt += it->second;
    }
}

void Solve()
{
    ll point1 = 0, point2 = 0;
    map<ll, ll>::iterator i = a.begin(), j = b.begin();
    while(i != a.end() && j != b.end())
    {
        if(i->first > j->first){
            point1 += 3 * loseB[j->first];
            j++;
        }
        else if(i->first < j->first){
            point2 += 3 * loseA[i->first];
            i++;
        }
        else{
            point1 += j->second, point2 += i->second;
            i++, j++;
        }
    }
    if(i != a.end()){
        while(i != a.end()){
            point1 += 3 * n;
            i++;
        }
    }
    else if(j != b.end()){
        while(j != b.end()){
            point2 += 3 * n;
            j++;
        }
    }
    cout << point1 << " " << point2 << endl;
}

int main()
{
    freopen("pigrace.inp", "r", stdin);
    freopen("pigrace.out", "w", stdout);

    ReadData();
    MakeMaps();
    Solve();

    return 0;
}
