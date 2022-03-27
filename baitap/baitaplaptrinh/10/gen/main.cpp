#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <string>

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
    if(square_root * square_root == n) return true;
    if(cube_primes.find(n) != cube_primes.end()) return true;
    return false;
}

void ReadLine(vector<ll> &v)
{
    string str; getline(cin, str);

    ll x = 0;
    for(int i = 0, len = str.length(); i < len; ++i){
        if(str[i] == ' ') {
            if(x != 0 && Check(x))
                v.push_back(x);
            x = 0;
        }
        else{
            x = x * 10 + str[i] - '0';
        }
    }
    if(x != 0 && Check(x))
        v.push_back(x);
}

void ReadData()
{
    a.push_back(0); b.push_back(0);
    ReadLine(a);
    ReadLine(b);

    for(int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    cout << "\n";
    for(int i = 0; i < b.size(); ++i)
        cout << b[i] << " ";
    cout << "\n";
}

ll Solve()
{
    ll lena = a.size(), lenb = b.size();
    for(ll i = 1; i <= lena; ++i){
        for(ll j = 1; j <= lenb; ++j){
            ll x = a[i], y = b[j];
            if(a[i] == b[j]){
                L[i][j] = L[i-1][j-1] + 1;
                cout << "a[" << i << "] = " << a[i] << " = " << b[j] << " = b[" << j << "]\n";
            }
            else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
}

    /*for(ll i = 1; i <= lena; ++i){
        for(ll j = 1; j <= lenb; ++j)
            cout << L[i][j] << ' ';
        cout << endl;
    }*/
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
