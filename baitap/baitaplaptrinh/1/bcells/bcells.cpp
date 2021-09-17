#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;

bool firstSpaceIsBlack(int r, int c)
{
    bool state=true;
    if(r%2==0) state=!state;
    if(c%2==0) state=!state;
    return state;
}

ll blackCells(int n, int m, int r, int c)
{
    ll sum=(ll)m*n;
    if(sum%2==0) return sum/2;
    if(firstSpaceIsBlack(r,c)) return sum/2+1;
    else return sum/2;
}

int main()
{
    freopen("bcells.inp","r",stdin);
    freopen("bcells.out","w",stdout);
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    cout<<blackCells(n,m,r,c);
    return 0;
}
