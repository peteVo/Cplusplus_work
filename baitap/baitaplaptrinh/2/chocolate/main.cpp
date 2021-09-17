#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int solvingWays(string s)
{
    long long cnt=1;
    int j=0;
    for(int i=0;i<=s.size();++i){
        if(s[i]=='X'){
            cnt=cnt*(i-j);
            j=i;
        }
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
