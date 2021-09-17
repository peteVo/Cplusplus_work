#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll n, S;
ll a[100001], s[200001];

void ReadData()
{
    s[0];
    cin >> n >> S;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        s[i] = s[i-1]+a[i];
    }
    for(ll i = n+1, m = 2*m; i < m; ++i){
        s[i] = s[i-1]+a[i%n];
    }
    //for(ll i = 1;i < 2*n; ++i) cout << s[i] << " ";
}

void SUMSEQ()
{
    ll i = 1, j = 1;
    ll m = 2*n-1;
    ll minI = 100001, minJ = 100001, minDif = 1e15;
    while(i <= n && j <= m && i <= j){
        if(j >= i+n) i++;
        ll val = s[j]-s[i-1];
        if(val >= S){
            if(val == S){
                if(j-i < minDif){
                    minI = i;
                    minJ = j;
                    minDif = minJ - minI+1;
                }
            }
            i++;
        }
        else j++;
    }
    if(minDif == 1e15)
        cout << 0;
    else
        cout << minI << " " << minDif;
}

int main()
{
    freopen("sumseq.inp", "r", stdin);
    freopen("sumseq.out", "w", stdout);

    ReadData();
    SUMSEQ();

    return 0;
}
