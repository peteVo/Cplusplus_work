#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

string S,T;

int GCD(int a, int b){
    int c;
    while(b != 0){
        c=a % b;
        a=b;
        b=c;
    }
    return a;
}

bool Check(string A,int k)
{
    int u=A.length()/k;
    for(int i=0;i<k;++i){
        for(int j=1;j<u;++j){
            if(A[i]!=A[k*j+i]) return false;
        }
    }
    return true;
}

void Solve()
{
    int s=S.length(), t=T.length(), k=GCD(s,t);
    if (Check(S,k)&&Check(T,k)){
        for(int i=0;i<k;++i) cout<<S[i];
    }
    else cout<<"NO";
}

int main()
{
    freopen("basestring.inp","r",stdin);
    freopen("basestring.out","w",stdout);
    cin>>S>>T;
    Solve();
    return 0;
}
