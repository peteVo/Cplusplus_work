#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, maxxplusy=0, minxplusy=0, maxxminusy=0, minxminusy=0;

void ReadData()
{
    cin>>n;
    int x,y;
    for(int i=1;i<=n;++i){
        cin>>x>>y;
        if(abs(x+y)>maxxplusy) maxxplusy=abs(x+y);
        if(abs(x+y)<minxplusy) minxplusy=abs(x+y);
        if(abs(x-y)>maxxplusy) maxxplusy=abs(x-y);
        if(abs(x-y)<minxplusy) minxplusy=abs(x-y);
    }
}

int maxdist()
{
    return max(maxxplusy-minxplusy,maxxminusy-minxminusy);
}

int main()
{
    freopen("mahdist.inp","r",stdin);
    freopen("mahdist.out","w",stdout);
    ReadData();
    cout<<maxdist();
    return 0;
}
