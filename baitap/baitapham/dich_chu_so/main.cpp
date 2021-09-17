#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int sochuso(int n)
{
    int k;
    for(k=0;n>0;++k){
        n/=10;
    }
    return k;
}

int sochuso10(int n)
{
    int k= sochuso(n), s=1 , i;
    for(i=1;i<k;++i){
        s*=10;
    }
    return s;
}

int rshift(int n)
{
    int k = sochuso(n),Max=n,i,p = sochuso10(n);
    for (i=1;i<k;++i){
        if(n%10==0)
            p/=10;
        n=(n%10)*p + n/10;
        if (Max<n)
            Max=n;
    }
    return Max;

}

int main()
{
    freopen("rshift.inp","r",stdin);
    freopen("rshift.out","w",stdout);
    int n;
    cin>>n;
    cout<<rshift(n);
    return 0;
}
