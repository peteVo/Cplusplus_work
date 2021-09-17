#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;

struct pii {
    int real,pos;
}a[100001];

bool tang(pii x, pii y)
{
    return( x.real < y.real );
}

void ReadData()
{
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].real;
        a[i].pos = i;
    }

    sort(a+1,a+1+n,tang);
}

int numberOfChanges()
{
    int cnt = 1, M = 1;
    for(int i = 2; i <= n; ++i){
        if( a[i].pos >= a[i-1].pos ){
            cnt++;
        }
        else{
            cnt = 1;
        }
        M = max(M,cnt);
    }
    return (n - M);
}

int main()
{
    freopen("lineup.inp", "r", stdin);
    freopen("lineup.out", "w", stdout);

    ReadData();

    cout<<numberOfChanges();

    return 0;
}
