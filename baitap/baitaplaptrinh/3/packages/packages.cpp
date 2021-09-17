#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int Package(int n)
{
    int five=n/5;
    n=n%5;
    if(n%3!=0) return -1;
    else return five+n/3;
}

int main()
{
    freopen("packages.inp","r",stdin);
    freopen("packages.out","w",stdout);
    int n;
    cin>>n;
    cout<<Package(n);
    return 0;
}
