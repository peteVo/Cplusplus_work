#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;

struct pii
{
    int a,b,pos;
}r[200001];

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>r[i].a>>r[i].b;
        r[i].pos=i;
    }
    sort(r+1,r+1+n,tang);
}

int main()
{
    freopen("roomsalloc.inp","r",stdin);
    freopen("roomsalloc.out","w",stdout);
    return 0;
}
