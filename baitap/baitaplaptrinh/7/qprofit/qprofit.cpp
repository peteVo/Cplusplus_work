#include <iostream>
#include <cstdio>
#include <cmath>
#define maxDay 100000

using namespace std;
typedef long long ll;
bool notPrime[maxDay+1] = {false};

ll n;
ll a[100001];
ll Q;
ll x[100001], y[100001];
ll s[100001];

void PrimeSieve()
{
    notPrime[0] = notPrime[1] = true;
    ll m = sqrt(maxDay+1);
    for(int i = 2; i <= m; ++i){
        if(!notPrime[i]){
            for(int j = i, threshold = (maxDay + 1)/i; j <= threshold; ++j){
                notPrime[i*j] = true;
            }
        }
    }
    //for(int i = 99900; i <= 100000; i++) cout << "isPrime[" << i << "]: " << !notPrime[i] << endl;;
}

void MakeSum()
{
    s[0] = 0;
    for(int i = 1; i <= n; ++i){
        if(a[i] > 0 && !notPrime[i]) s[i] = s[i-1];
        else s[i] = s[i-1] + a[i];
        //cout << "s[" << i << "]: " << s[i] << endl;
    }
    //cout << endl;
}

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    cin >> Q;
    for(int i = 1; i <= Q; ++i){
        cin >> x[i] >> y[i];
    }
}

void Solve()
{
    for(int i = 1; i <= Q; ++i){
        cout << s[y[i]] - s[x[i]-1] << endl;
    }
}

int main()
{
    freopen("qprofit.inp", "r", stdin);
    freopen("qprofit.out", "w", stdout);

    PrimeSieve();
    ReadData();
    MakeSum();
    Solve();

    return 0;
}
