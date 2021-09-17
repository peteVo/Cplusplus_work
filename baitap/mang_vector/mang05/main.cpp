#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int a[1000002], n;

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
}

int MinValPos(int avoidPos)
{
    int posVal;
    if(avoidPos==1) posVal=2;
    else posVal=1;
    for(int i=1;i<=n;++i){
        if(a[i]<a[posVal] && i!=avoidPos) posVal=i;
    }
    return posVal;
}

int main()
{
    freopen("mang05.inp","r",stdin);
    freopen("mang05.out","w",stdout);
    ReadData();
    int x1=MinValPos(0);
    int x2=MinValPos(x1);
    cout<<x1<<" "<<x2;
    return 0;
}
