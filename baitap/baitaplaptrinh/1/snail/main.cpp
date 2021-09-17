#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int Days(int v, int a, int b)
{
    int c=a-b,cnt;
    while(v>b){
        v-=c;
        cnt++;
    }
    return cnt;
}
int main()
{
    freopen("snail.inp","r",stdin);
    freopen("snail.out","w",stdout);
    int v,a,b;
    cin>>a>>b>>v;
    cout<<Days(v,a,b);
    return 0;
}
