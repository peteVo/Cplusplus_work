#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

long long n, x[1001], y[1001], pos;
double z, t=1e23;

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
}

int minPoint()
{
    for(int i=1;i<=n;i++){
        z=0;
        for(int j=1; j<=n; j++){
            z+=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        }
        if(z<t){
            t=z;
            pos=i;
        }
    }
    return pos;
}

int main()
{
    freopen("mindist.inp","r",stdin);
    freopen("mindist.out","w",stdout);
    ReadData();
    cout<<minPoint();
    return 0;
}
