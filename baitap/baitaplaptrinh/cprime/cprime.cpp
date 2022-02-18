#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const ll maxN = 1000000;

bool notPrime[maxN + 1] = {false};
ll divs[maxN + 1] = {0};
ll s[maxN + 1] = {0};

void Sieve()
{
    notPrime[0] = true, notPrime[1] = true;
    ll m = sqrt(maxN);
    for(ll x = 2; x <= m; ++x){
        if(!notPrime[x]){
            for(ll y = x, len = maxN / x; y <= len; ++y){
                notPrime[x*y] = true;
            }
        }
    }

    for(int x = 1; x <= m; ++x){
        divs[x*x]++;
        for(int y = x + 1, len = maxN/x; y <= len; ++y){
            divs[x*y] += 2;
        }
    }
}

void Prep()
{
    for(int i = 1; i <= maxN; ++i){
        if(!notPrime[divs[i]]) s[i] = s[i-1] + 1;
        else s[i] = s[i-1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("cprime.inp", "r", stdin);
    freopen("cprime.out", "w", stdout);

    Sieve();
    Prep();
    ll T; cin >> T;
    for(int i = 0; i < T; ++i){
        ll a, b; cin >> a >> b;
        cout << s[b] - s[a-1] << "\n";
    }

    return 0;
}

