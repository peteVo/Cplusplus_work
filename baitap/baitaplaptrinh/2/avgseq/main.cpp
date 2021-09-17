#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n, b[101];

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
}

void Solve()
{
    cout<<b[1]<<" ";
    for(int i=2;i<=n;i++){
        int x=(i*b[i])-((i-1)*b[i-1]);
        cout<<x<<" ";
    }
}

int main()
{
    freopen("avgseq.inp","r",stdin);
    freopen("avgseq.out","w",stdout);
    ReadData();
    Solve();
    return 0;
}
