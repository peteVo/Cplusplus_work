#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[300001];

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

int Solve()
{
    int len = n, c = 0;
    for(int j = 31; j >= 0; --j){
        int b = 0;
        for(int i = 1; i <= n; ++i){
            if(a[i] >> j & 1) b++;
        }
        if(b > 1){
            for(int i = 1; i <= n; ++i){
                if(!(a[i] >> j & 1)) a[i] = 0, len--;
            }
            c += 1 << j;
        }
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ando.inp", "r", stdin);
    freopen("ando.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
