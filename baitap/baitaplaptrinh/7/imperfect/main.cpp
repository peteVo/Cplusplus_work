#include <iostream>
#include <cstdio>
#include <cmath>
#define maxN 10000000

using namespace std;
typedef long long ll;
ll imperfection[maxN+1] = {0};
ll sumImp[maxN+1] = {0};
ll sumDiv[maxN+1] = {0};

void MakeSumDiv()
{
    ll m = sqrt(maxN);
    for(ll i = 1; i <= m; ++i){
        sumDiv[i*i]+= i;
        for(int j = i+1, temp = maxN/i; j <= temp; ++j){
            sumDiv[i*j]+= i+j;
        }
    }
    //for(ll i = 1; i <= 20; ++i) cout << "sumDiv[" << i << "]: " << sumDiv[i] << endl;
}

void MakeImperfection()
{
    for(ll i = 1; i <= maxN; ++i){
        imperfection[i] = abs(sumDiv[i]-2*i);
    }
}

void MakeSumImp()
{
    sumImp[0] = 0;
    for(ll i = 1; i <= maxN; ++i){
        sumImp[i] = sumImp[i-1] + imperfection[i];
    }
}

int main()
{
    freopen("imperfect.inp", "r", stdin);
    freopen("imperfect.out", "w", stdout);

    MakeSumDiv();
    MakeImperfection();
    MakeSumImp();
    ll a, b;
    cin >> a >> b;
    cout << sumImp[b] - sumImp[a-1];

    return 0;
}
