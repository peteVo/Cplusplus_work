#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, meetings[1000001];
struct pii
{
    int x,y,z;
}a[1000001];

bool tang(pii z, pii t)
{
    return(z.x<t.x || (z.x==t.x && z.y<t.y));
}

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].x>>a[i].y;
        a[i].z=i;
    }
    sort(a+1,a+1+n,tang);
}

void meets()
{
    int endtime=0,cnt=0;
    for(int i=1;i<=n;++i){
        if(a[i].x>=endtime){
            endtime=a[i].y;
            meetings[++cnt]=a[i].z;
        }
    }
    cout<<cnt<<"\n";
    for(int i=1;i<=cnt;++i) cout<<meetings[i]<<"\n";
}

int main()
{
    freopen("meeting.inp","r",stdin);
    freopen("meeting.out","w",stdout);
    ReadData();
    meets();
    return 0;
}
