#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int t,m,n,p,q;
string mn[1001],pq[1001];

bool isMatching(int x,int y)
{
    for(int i=1;i<=p;++i){
        for(int k=1;k<=q;++k){
            if(mn[y+i-1][x+k-1]!=pq[i][k]) return false;
        }
    }
    return true;
}

void ReadData()
{
    cin>>t;
    for(int i=1;i<=t;++i){
        bool state=false;
        cin>>m>>n;
        for(int k=1;k<=m;++k){
            cin>>mn[k];
        }
        cin>>p>>q;
        for(int k=1;k<=p;++k){
            cin>>pq[k];
        }
        for(int k=1;k<=m-p+1;++k){
            for(int d=1;d<=n-q+1;++d){
                if(isMatching(d,k)&&(!state)){
                    state=!state;
                    cout<<"YES";
                }
            }
        }
        if(!state) cout<<"NO";
    }
}

int main()
{
    freopen("grid.inp","r",stdin);
    freopen("grid.out","w",stdout);
    ReadData();
    return 0;
}
