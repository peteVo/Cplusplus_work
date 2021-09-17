#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int a[10001], n;

bool isPrime(int n)
{
    if(n<2) return false;
    int m = sqrt(n);
    for(int i=2;i<=m;++i){
        if(n%i==0) return false;
    }
    return true;
}

int primeCount()
{
    int cnt=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(isPrime(a[i])) ++cnt;
    }
    return cnt;
}

int main()
{
    freopen("mang03.inp","r",stdin);
    freopen("mang03.out","w",stdout);
    cout<<primeCount();
    return 0;
}
