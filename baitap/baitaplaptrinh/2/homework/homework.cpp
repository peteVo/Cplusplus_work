#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int time[1001], a[1001], b, n, m, sumtime=0;
bool work[1001];

void ReadData()
{
    cin>>n>>m;
    for(int i=0; i<n; ++i){
        cin>>time[i+1];
        sumtime+=time[i+1];
    }
    for(int i=0; i<m; ++i){
        cin>>a[i+1]>>b;
    }
    for(int i=0; i<n; ++i){
        work[i+1]=true;
    }
}

int Solve()
{
    for(int i=1; i<=m; ++i){
        work[a[i]]=false;
    }
    int M=0;
    for(int i=1; i<=n; ++i){
        if(work[i]) M=max(M,time[i]);
    }
    return sumtime-M;
}

int main()
{
    freopen("homework.inp","r",stdin);
    freopen("homework.out","w",stdout);
    ReadData();
    cout<<Solve();
    return 0;
}
