#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[100001];

void ReadData()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
}

int maxfrequency()
{
    sort(a+1,a+1+n);
    int M=a[1], cnt=1, maxi=0;
    for(int i=2;i<=n;++i){
        if(a[i]!=a[i-1]){
            if(cnt>maxi) {
                maxi=cnt;
                M=a[i-1];
            }
            cnt=1;
        }
        else cnt++;
    }
    return M;
}

int main()
{
    freopen("maxfreq.inp","r",stdin);
    freopen("maxfreq.out","w",stdout);
    ReadData();
    cout<<maxfrequency();
    return 0;
}
