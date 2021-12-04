#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

ll n;
ll a[5002];
map<ll, int> m;

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        m[a[i]]++;
    }
}

void Solve()
{
    for(map<ll, int>::iterator it1 = m.begin(); it1 != m.end(); ++it1){
        int ai = it1->first;
        map<ll, int>::iterator temp = it1;
        temp++;
        for(map<ll, int>::iterator it2 = temp; it2 != m.end(); ++it2){
            int aj = it2->first;
            int delta = aj - ai;
            map<ll, int>::iterator it3 = m.find(aj + delta);
            if(it3 != m.end()){
                int ak = it3->first;
                cout << ai << " " << aj << " " << ak << endl;
                return;
            }
        }
    }
}

int main()
{
    freopen("triple.inp", "r", stdin);
    freopen("triple.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
