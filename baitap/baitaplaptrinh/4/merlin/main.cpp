#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n, a[100001],s=0;
void ReadData()
{
    cin>>n;

    for(ll i=1;i<=n;++i){
        cin>>a[i];
        s=s+a[i];
    }
    sort(a+1,a+1+n);
}

ll leastBottles()
{
    ll s1=a[n],s2=a[n-1]*(n-1)-s+s1,i=n-1,cnt=0;
    while(s2>s1){
        s1=s1+a[i];
        s2=a[i]*i-s+s1;
        cnt++;
        i--;
    }
    return cnt;
}

int main()
{
    freopen("merlin.inp","r",stdin);
    freopen("merlin.out","w",stdout);
    ReadData();
    cout<<leastBottles();
    return 0;
}
