#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    freopen("words.inp","r",stdin);
    freopen("words.out", "w",stdout);
    string s;
    int cnt=0, M=0;
    while(cin>>s){
        cnt++;
        M=max(M,(int)s.size());
    }
    cout<<cnt<<" "<<M;
    return 0;
}
