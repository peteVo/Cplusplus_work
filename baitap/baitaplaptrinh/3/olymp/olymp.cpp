#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,c,k,heso[1000001];

struct pii
{
    int a,b;
}tt[1000001];

void ReadData()
{
    cin>>n>>c>>k;
    for(int i=1;i<=n;++i){
        cin>>tt[i].a>>tt[i].b;
        if(tt[i].a>=k) heso[i]=0;
        else{
            if(tt[i].b==0) heso[i]=1e9;
            else heso[i]=(k-tt[i].a-1)/tt[i].b+1;
        }
    }
    sort(heso+1,heso+1+n);
}

int maxStudent()
{
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(k-heso[i]>=0){
            cnt++;
            k-=heso[i];
        }
        else return cnt;
    }
}

int main()
{
    freopen("olymp.inp","r",stdin);
    freopen("olymp.out","w",stdout);
    ReadData();
    cout<<maxStudent();
    return 0;
}
