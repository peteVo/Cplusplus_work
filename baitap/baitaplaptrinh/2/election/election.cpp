#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n,m,a[1001][1001], citywinner[1001], b[1001];

void ReadData()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
}

void Phaseone()
{
    for(int i=1;i<=m;++i){
        int M=-1;
        for(int j=1;j<=n;++j){
            if(a[i][j]>M){
                M=a[i][j];
                citywinner[i]=j;
            }
        }
    }
}

int Phasetwo()
{
    for(int i=1;i<=m;++i){
        b[citywinner[i]]++;
    }
    int M=0, winner=0;
    for(int i=1;i<=n;++i){
        if(b[i]>M){
            M=b[i];
            winner=i;
        }
    }
    return winner;
}

int main()
{
    freopen("election.inp","r",stdin);
    freopen("election.out","w",stdout);
    ReadData();
    Phaseone();
    cout<<Phasetwo();
    return 0;
}
