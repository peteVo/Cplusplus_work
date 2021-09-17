#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int solvingWays(string s)
{
    long long cnt=1;
    int counter=1;
    for(int i=1;i<=s.size();++i){
        if(s[i]=='O') counter++;
        else {cnt=cnt*counter;counter=1;}
    }
    return cnt;
}

int main()
{
    freopen("chocolate.inp","r",stdin);
    freopen("chocolate.out","w",stdout);
    string s;
    cin>>s;
    cout<<solvingWays(s);
    return 0;
}
