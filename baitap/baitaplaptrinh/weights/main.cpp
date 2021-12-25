#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef unsigned long long ll;
const ll INF = 1e18;

vector<ll> mul3;
ll len_mul3 = 0;

void Build()
{
    ll k = 1; mul3.push_back(k);
    len_mul3 = 1;
    while(k < INF){
        k*=3; mul3.push_back(k);
        len_mul3++;
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("weights.inp", "r", stdin);
    freopen("weights.out", "w", stdout);



    return 0;
}
