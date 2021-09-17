#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

void Colors(int m,int n)
{
    int Blue=0,Green=0,Red=0,Black=0;
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(i*j%5==0) Blue++;
            else if(i*j%3==0) Green++;
            else if(i*j%2==0) Red++;
            else Black++;
        }
    }
    cout<<Red<<"\n"<<Green<<"\n"<<Blue<<"\n"<<Black;
}

int main()
{
    freopen("coloring.inp","r",stdin);
    freopen("coloring.out","w",stdout);
    int m,n;
    cin>>m>>n;
    Colors(m,n);
    return 0;
}
