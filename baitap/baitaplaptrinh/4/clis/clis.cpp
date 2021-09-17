#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[200001];

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i+n]=a[i];
    }
}

void maxSeq()
{
    int i=1,M=0,Start,End;
    while(i<=n){
        int j=i+1;
        while((j-i+1)<=2*n && a[j]>=a[j-1]){
            if(j-i+1>M){
                M=j-i+1;
                End=j;
                Start=j-M+1;
            }
            j++;
        }
        i=j;
    }
    Start=(Start-1)%n+1;
    End=(End-1)%n+1;
    cout<<Start<<" "<<End;
}

int main()
{
    freopen("clis.inp","r",stdin);
    freopen("clis.out","w",stdout);
    ReadData();
    maxSeq();
    return 0;
}
