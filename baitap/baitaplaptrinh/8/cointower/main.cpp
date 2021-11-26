#include <iostream>
#include <cmath>
#include <cstdio>

const int maxN = 1e6;

using namespace std;

int K, L, m;
int n[51];
bool f[maxN + 1] = {false};

void MakeF()
{
    f[1] = f[K] = f[L] = true;
    for (int i = 1; i <= maxN; ++i)
    {
        if(f[i] == false){
            if(i + 1 <= maxN) f[i + 1] = true;
            if(i + L <= maxN) f[i + L] = true;
            if(i + K <= maxN) f[i + K] = true;
        }
    }
}

int main()
{
    freopen("cointower.inp", "r", stdin);
    freopen("cointower.out", "w", stdout);

    cin >> K >> L >> m;
    MakeF();
    for (int i = 1; i <= m; ++i)
    {
        cin >> n[i];
        if(f[n[i]] == true) cout << "A";
        else cout << "B";
    }

    return 0;
}
