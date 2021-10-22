#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
vector<ll> p;
int n;

void ReadData()
{
    ll x;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x;
        p.push_back(x);
    }
    sort(p.begin(), p.end());
    //for(int i = 0; i < p.size(); ++i) cout << p[i] << " ";
    //cout << endl;
}

int median()
{
    int len = p.size();
    if(len % 2 != 0) return len / 2;
    else {
        if(p[len / 2 - 1] <= p[len / 2]) return len / 2 - 1;
        else return len / 2;
    }
}

void PrintP()
{
//    for(int i = )
}

void Solve()
{
    for(int i = 0; i < n; ++i){
        int pos = median();
        ll tmp = p[pos];
        p.erase(p.begin() + pos);
        cout << tmp << " ";
        //for(int i = 0; i < p.size(); ++i) cout << p[i] << " ";
        //cout << endl;
    }
}

int main()
{
    freopen("killingseq.inp", "r", stdin);
    freopen("killingseq.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
