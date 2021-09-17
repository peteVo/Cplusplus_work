#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int cnt[5001];

void ReadData()
{
    for(int a=3;a<=5000;++a){
        for(int b=a+1;b<=5000-a;++b){
            int c=a*a+b*b, d=sqrt(c);
            if((d*d==c)&&(a+b+d<=5000)) ++cnt[a+b+d];
        }
    }
}

int main()
{
    freopen("pythagore.inp","r",stdin);
    freopen("pythagore.out","w",stdout);
    ReadData();
    int t,P;
    cin>>t;
    for(int i=1;i<=t;++i){
        cin>>P;
        cout<<cnt[P]<<"\n";
    }
    return 0;
}
