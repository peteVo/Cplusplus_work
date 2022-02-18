#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <climits>
#include <set>

using namespace std;
typedef unsigned long long ll;

const ll maxN = 1000000;

set<ll> cube_primes;
bool notPrime[maxN+1] = {false};
vector<ll> a, b;
vector<ll> all;
ll L[1001][1001] = {0};

void Sieve()
{
    notPrime[0] = true, notPrime[1] = true;
    ll m = sqrt(maxN);
    for(ll x = 2; x <= m; ++x)
        if(notPrime[x] == false)
            for(ll y = x, len = maxN/x; y <= len; ++y)
                notPrime[x*y] = true;

    for(ll i = 2; i <= maxN; ++i){
        cube_primes.insert(i * i * i);
    }
}

bool Check(ll n)
{
    ll square_root = sqrt(n);
    if(square_root * square_root == n && !notPrime[square_root]) return true;
    if(cube_primes.find(n) != cube_primes.end()) return true;
    return false;
}

void ReadData()
{
    ll x;
    while(cin >> x){
        all.push_back(x);
    }
    ll l = all.size();

    for(ll i = 0; i < l/2; ++i){
        if(Check(all[i])) a.push_back(all[i]);
    }
    for(ll i = l/2; i < l; ++i){
        if(Check(all[i])) b.push_back(all[i]);
    }

    for(ll i = 0; i < a.size(); ++i) cout << a[i] << " ";
    cout << endl;
    for(ll i = 0; i < b.size(); ++i) cout << b[i] << " ";
    cout << endl;
}

ll Solve()
{
    ll lena = a.size(), lenb = b.size();
    for(ll i = 1; i <= lena; ++i)
        for(ll j = 1; j <= lenb; ++j)
            if(Check(a[i-1]) && Check(b[j-1]) && a[i-1] == b[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else L[i][j] = max(L[i-1][j], L[i][j-1]);

    return L[lena][lenb];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("gen.inp", "r", stdin);
    freopen("gen.out", "w", stdout);

    Sieve();
    ReadData();
    cout << Solve();

    return 0;
}
