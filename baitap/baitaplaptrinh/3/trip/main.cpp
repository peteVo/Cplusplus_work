#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int n,d,m[100001];

void ReadData(int x)
{
    n = x;
    cin >> d;
    for(int i =1; i <= n; ++i) cin>>m[i];
    sort(m + 1, m + 1 + n);
}

int MinBoats()
{
    int i = 1, j = n, cnt = 0;
    while(i <= j) {
        if( m[i] + m[j] <= d) {++i;--j;}
        else j--;
        cnt++;
    }
    return cnt;
}

int main()
{
    freopen("trip.inp","r",stdin);
    freopen("trip.out","w",stdout);
    int x;
    while(cin>>x){
        ReadData(x);
        cout << MinBoats() << endl;
    }
    return 0;
}
