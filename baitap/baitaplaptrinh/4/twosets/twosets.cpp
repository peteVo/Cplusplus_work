#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

void twoArrays(int n)
{
    if(n%4!=0 && n%2==0){
        cout<<"NO";
        return;
    }
    if(n%4==0)
    {
        cout<<"YES"<<"\n"<<n/2<<"\n";
        for(int i=1;i<=n-3;i=i+4){
            cout<<i<<" "<<i+3<<" ";
        }
        cout<<"\n"<<n/2<<"\n";
        for(int i=2;i<=n-2;i=i+4){
            cout<<i<<" "<<i+1<<" ";
        }
        return;
    }
    if((n-3)%4==0){
        cout<<"YES"<<"\n"<<n/2+1<<"\n"<<1<<" "<<2<<" ";
        for(int i=4;i<=n-3;i=i+4){
            cout<<i<<" "<<i+3<<" ";
        }
        cout<<"\n"<<n/2<<"\n"<<3<<" ";
        for(int i=5;i<=n-2;i=i+4){
            cout<<i<<" "<<i+1<<" ";
        }
        return;
    }
    cout<<"NO";
    return;
}

int main()
{
    freopen("twosets.inp","r",stdin);
    freopen("twosets.out","w",stdout);
    int n;
    cin>>n;
    twoArrays(n);
    return 0;
}
