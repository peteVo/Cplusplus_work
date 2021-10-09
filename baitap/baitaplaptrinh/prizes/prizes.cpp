#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
int n, k;
ll a[100001];
ll s[100001];

void ReadData()
{
    cin >> n >> k;
    s[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
}

ll maxPrize()
{
    ll max1 = -1, max2 = -1;
    for(int i = 1; i <= n - k + 1; ++i){
        ll val = s[i + k - 1] - s[i - 1];
        if(max1 < val){
            max2 = max1, max1 = val;
        }
        else if(max2 < val){
            max2 = val;
        }
        //cout << "max1: " << max1 << ", max2: " << max2 << endl;
    }
    return max2;
}

int main()
{
    freopen("prizes.inp", "r", stdin);
    freopen("prizes.out", "w", stdout);

    ReadData();
    cout << maxPrize();

    return 0;
}
