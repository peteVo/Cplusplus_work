#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
int n,P[2000001];
struct pii
{
    int x,y,z;
}a[100001];

bool sorter(pii c, pii d)
{
    return(c.z<d.z || (c.z==d.z &&  c.x<d.x));
}

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;++i){cin>>a[i].x>>a[i].z;a[i].y=a[i].z-1;}
    sort(a+1,a+1+n,sorter);
}

void representatives()
{
    int cnt=2;
    P[1]=a[1].y;
    P[2]=a[1].z;
    for(int i=1;i<=n;++i){
        if((!(P[cnt]>=a[i].x && P[cnt]<=a[i].z)) && (!(P[cnt-1]>=a[i].x && P[cnt-1]<=a[i].z))){
            P[++cnt]=a[i].y;
            P[++cnt]=a[i].z;
        }
        else if(((!(P[cnt]>=a[i].x && P[cnt]<=a[i].z)) && (P[cnt-1]>=a[i].x && P[cnt-1]<=a[i].z)) || (P[cnt]>=a[i].x && P[cnt]<=a[i].z) && (!(P[cnt-1]>=a[i].x && P[cnt-1]<=a[i].z))){
            if(P[cnt]==a[i].z){
                P[cnt]=a[i].y;
                P[++cnt]=a[i].z;
            }
            else P[++cnt]=a[i].z;
        }
    }
    cout<<cnt<<"\n";
    for(int i=1;i<=cnt;++i) cout<<P[i]<<" ";
}

int main()
{
    freopen("rep.inp","r",stdin);
    freopen("rep.out","w",stdout);
    ReadData();
    representatives();
    return 0;
}
