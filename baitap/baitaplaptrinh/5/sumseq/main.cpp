#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, S, a[100001], s[100001];

void ReadData()
{
    cin >> n >> S;
    s[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
}



int main()
{
    freopen("sumseq.inp", "r", stdin);
    freopen("sumseq.out", "w", stdout);



    return 0;
}
