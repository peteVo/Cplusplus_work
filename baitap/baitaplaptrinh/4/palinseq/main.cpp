#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n, a[1000001];
void ReadData()
{
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
}

ll minChange()
{
    int i=1,j=n,cnt=0;
    while(i<j){
        if(a[i]<a[j]){
            i++;
            a[i]=a[i]+a[i-1];
            cnt++;
        }
        else if(a[i]>a[j]){
            j--;
            a[j]=a[j]+a[j+1];
            cnt++;
        }
        else{i++;j--;};
    }
    return cnt;
}

int main()
{
    freopen("palinseq.inp","r",stdin);
    freopen("palinseq.out","w",stdout);
    ReadData();
    cout<<minChange();
    return 0;
}
