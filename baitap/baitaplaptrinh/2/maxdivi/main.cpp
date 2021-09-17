#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n=0, a[1000001];

int UCLN(int x,int y)
{
    x=abs(x);
    y=abs(y);
    int z;
    while(y>0){
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}


int Solve()
{
    cin>>a[1]>>a[2];
    int n=2, i=3;
    int M=a[2]-a[1];
    while(cin>>a[i]){
        n++;
        M=UCLN(M,a[i]-a[1]);
        i++;
    }
    return M;
}

int main()
{
    freopen("maxdivi.inp","r",stdin);
    freopen("maxdivi.out","w",stdout);
    cout<<Solve();
    return 0;
}
