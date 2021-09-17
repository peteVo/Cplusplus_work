#include <iostream>
#include <cstdio>
#define maxN 1000000

using namespace std;
typedef long long ll;
ll u[maxN+1], v[maxN+1];
ll uS[maxN+1], vS[maxN+1];

void DivisorSieve()
{
    uS[0] = vS[0] = 0;
    for(ll i = 1; i <= maxN; ++i){
        for(ll j = i; j <= maxN; j+=i){
            u[j]++;
            v[j]+=i;
        }
    }
    for(int i = 1; i <= maxN; ++i){
        uS[i] = uS[i-1]+u[i];
        vS[i] = vS[i-1]+v[i];
    }
    return;
}

void DivisorPrinter(ll s, ll e)
{
    /*ll sumU = 0, sumV = 0;
    for(ll i = s; i <= e; ++i){
        sumU += u[i];
        sumV += v[i];
    }*/
    cout << uS[e]-uS[s-1] << " " << vS[e]-vS[s-1] << endl;
    return;
}

int main()
{
    freopen("divisors.inp", "r", stdin);
    freopen("divisors.out", "w", stdout);

    DivisorSieve();
    ll T;
    cin >> T;
    for(ll i = 0; i < T; ++i){
        int s,e;
        cin >> s >> e;
        DivisorPrinter(s,e);
    }

    return 0;
}
