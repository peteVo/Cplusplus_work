#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int Solve(string s)
{
    int a,sum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!='H' && s[i]!='O' && s[i]!='N' && s[i]!='C') sum=sum+a*(s[i]-'1');
        if(s[i]=='H'){
            sum=sum+1;
            a=1;
        }
        if(s[i]=='O'){
            sum=sum+16;
            a=16;
        }
        if(s[i]=='N'){
            sum=sum+14;
            a=14;
        }
        if(s[i]=='C'){
            sum=sum+12;
            a=12;
        }
    }
    return sum;
}

int main()
{
    freopen("molecular.inp","r",stdin);
    freopen("molecular.out","w",stdout);
    string s;
    cin>>s;
    cout<<Solve(s);
    return 0;
}
