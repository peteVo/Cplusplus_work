#include <iostream>
#include <cstdio>
#include <cmath>
#define maxN 500

using namespace std;
typedef long long ll;

ll A, B, n;
ll c[maxN+1], m[maxN+1];
ll x[maxN+1][501];

void ReadData()
{
    cin >> A >> B >> n;
    for(int i = 1; i <= n; ++i){
        cin >> c[i] >> m[i];
        for(int j = 1; j <= m[i]; ++j){
            cin >> x[i][j];
        }
    }
}

ll minFee()
{
    ll minfee = 1001;
    for(int i = 1; i <= n; ++i){
        bool flagA = false;
        for(int j = 1; j <= m[i]; ++j){
            if(x[i][j] == A) flagA = true;
            if(x[i][j] == B){
                if(flagA){
                    minfee = min(minfee, c[i]);
                }
                else break;
            }
        }
    }
    if(minfee==1001) return -1;
    else return minfee;
}

int main()
{
    freopen("busroute.inp", "r", stdin);
    freopen("busroute.out", "w", stdout);

    ReadData();
    cout << minFee();

    return 0;
}
