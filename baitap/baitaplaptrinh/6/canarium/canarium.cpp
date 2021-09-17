#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

void MinCanarium(ll k)
{
    bool hasSolution = false;
    k *= 2;
    ll maxMN = sqrt(k);
    ll m, n;
    ll minN = 1e8, minM = 1e8;
    ll minMN = 1e14;

    for(ll i = 1; i <= maxMN; ++i){
        m = i;
        n = (k - m - 1) / (2 * m + 1);
        if((n + 1) * (m + 1) + m * n == k && abs(m - n) < minMN){
                minN = n;
                minM = m;
                minMN = abs(m - n);
                hasSolution = true;
        }
    }
    if(hasSolution) minM < minN ? cout << minM << " " << minN << endl : cout << minN << " " << minM << endl;
    else cout << "-1 -1" << endl;
}

int main()
{
    freopen("canarium.inp", "r", stdin);
    freopen("canarium.out", "w", stdout);

    ll k;
    while(cin >> k) MinCanarium(k);

    return 0;
}
