#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n,t[100001];

void ReadData()
{
    cin>>n;
    for(ll i = 1; i <= n; ++i) cin>>t[i];
}

void Solve()
{
    ll m1 = 0, m2 = 0, i = 1, j = n;

    while( i <= j ){

        if(m1 < m2) m1 = m1 + t[i++];
        else if(m1 > m2) m2 = m2 + t[j--]*2;
        else {
            if( i < j ) m1 = m1 + t[i++], m2 = m2 + t[j--]*2;
            else  m1 = m1 + t[i++];
        }

    }
    cout << i-1 << " " << n - i + 1 << "\n";
}

int main()
{
    freopen("distribution.inp","r",stdin);
    freopen("distribution.out","w",stdout);
    ll test;
    cin>>test;
    for(ll i=1;i<=test;++i){
        ReadData();
        Solve();
    }
    return 0;
}
