#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
int a[1000001];

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

long long Solve()
{
    long long res = 0;
    for(int j = 0; j <= 31; ++j){
        long long one_count = 0, zero_count = 0;
        for(int i = 1; i <= n; ++i){
            if(a[i] & 1) one_count++;
            else zero_count++;
            a[i] >>= 1;
        }
        res += one_count * zero_count * (1 << j);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sumxor.inp", "r", stdin);
    freopen("sumxor.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
