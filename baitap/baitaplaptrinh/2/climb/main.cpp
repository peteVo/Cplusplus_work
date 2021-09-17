#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n, h[100001];

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>h[i];
    }
}

int maxHeight()
{
    int mH=0,a,b;
    a=h[1];
    for(int i=2;i<=n;i++){
        if(h[i+1]<=h[i]){
            if(mH<h[i]-a) mH=h[i]-a;
            a=h[i+1];
        }
    }
    return mH;
}

int main()
{
    freopen("climb.inp","r",stdin);
    freopen("climb.out","w",stdout);
    ReadData();
    cout<<maxHeight();
    return 0;
}
