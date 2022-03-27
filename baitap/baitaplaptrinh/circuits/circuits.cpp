#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

int m, n;
int a[1001] = {0}, b[1001] = {0};
int L[1001][1001] = {0};

int ReadBits(ll x)
{
    int ans = 0;
    while(x > 0){
        if(x&1) ans++;
        x>>=1;
    }
    return ans;
}

void ReadData()
{
    ll x;
    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        cin >> x;
        a[i] = ReadBits(x);
        //cout << a[i] << " ";
    }
    //cout << endl;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        b[i] = ReadBits(x);
        //cout << b[i] << " ";
    }
    //cout << endl;
}

int Solve()
{
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(a[i] == b[j])
                L[i][j] = L[i-1][j-1] + 1;
            else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("circuits.inp", "r", stdin);
    freopen("circuits.out", "w", stdout);

    ReadData();
    cout << Solve();
    //cout << ReadBits((ll)26);

    return 0;
}
