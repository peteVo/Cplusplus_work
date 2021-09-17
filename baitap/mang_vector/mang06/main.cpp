#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int a[1000001], n;

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
}

bool isPrime(int val)
{
    if(val<2) return false;
    int m=sqrt(val);
    for(int i=2;i<=m;++i){
        if(val%i==0) return false;
    }
    return true;
}

int minPrime()
{
    int pos=1;
    bool prime;
    if(isPrime(a[pos])) prime=true;
    else prime=false;
    for(int i=1;i<=n;++i){
        if(isPrime(a[i]) && a[i]>a[pos]){
            pos=i;
            prime=true;
        }
    }
    if(prime) return pos;
    else return -1;
}

int main()
{
    freopen("mang06.inp","r",stdin);
    freopen("mang06.out","w",stdout);
    ReadData();
    cout<<minPrime();
    return 0;
}
