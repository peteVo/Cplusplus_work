#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[100001];
char b[200002];

void PrintBracks()
{
    int pos=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        while(b[pos]=='('||b[pos]==')') pos++;
        b[pos]='(';
        b[pos+a[i]+1]=')';
    }
}

int main()
{
    freopen("brackets.inp","r",stdin);
    freopen("brackets.out","w",stdout);
    PrintBracks();
    for(int i=1;i<=2*n;i++) cout<<b[i];
    return 0;
}
