#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[100001][3];

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2];
    }
}

int cashiers()
{
    int cnt=1,M=1;
    for(int i=2;i<=n;i++){
        if(a[i][1]==a[i-1][1] && a[i][2]==a[i-1][2]){
            cnt++;
            if(cnt>M) M=cnt;
        }
        else cnt=1;
    }
    return M;
}

int main()
{
    freopen("freecash.inp","r",stdin);
    freopen("freecash.out","w",stdout);
    ReadData();
    cout<<cashiers();
    return 0;
}
