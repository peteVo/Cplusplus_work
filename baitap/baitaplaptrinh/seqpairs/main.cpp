#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

ll m, n;
ll a[1001], b[1001], sa[1001] = {0}, sb[1001] = {0};

void ReadData()
{
    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        cin >> a[i];
        sa[i] = sa[i-1] + a[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
        sb[i] = sb[i-1] + b[i];
    }
}

ll Choices()
{
    ll ans = 0;
    map<ll, ll> ma, mb;
    for(int i = 0; i < m; ++i){
        for(int j = i + 1; j <= m; ++j){
            int sum = sa[j] - sa[i];
            ma[sa[j] - sa[i]]++;
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j <= n; ++j){
            int sum = sb[j] - sb[i];
            mb[sb[j] - sb[i]]++;
        }
    }
    for(map<ll, ll>::iterator it1 = ma.begin(); it1 != ma.end(); ++it1){
        int sum = it1->first;
        map<ll, ll>::iterator it2 = mb.find(it1->first);
        if(it2 != mb.end()){
            ans += it1->second * it2->second;
        }
    }
    return ans;
}

int main()
{
    freopen("seqpairs.inp", "r", stdin);
    freopen("seqpairs.out", "w", stdout);

    ReadData();
    cout << Choices();

    return 0;
}
