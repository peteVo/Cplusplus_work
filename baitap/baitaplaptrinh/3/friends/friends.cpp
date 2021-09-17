#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,B,s[100001];

void ReadData()
{
    cin>>n>>B;
    for(int i=1;i<=n;++i){
        cin>>s[i];
    }
    sort(s+1,s+1+n);
}

int lower(int x,int lo,int hi)
{
    int pos=-1,m;
    while (lo<=hi){
        m=(lo+hi)/2;
        if(s[m]>=x){
            if(s[m]==x) pos=m;
            hi=m-1;
        }
        else lo=m+1;
    }
    return pos;
}

int upper(int x,int lo,int hi)
{
    int pos=-1,m;
    while (lo<=hi){
        m=(lo+hi)/2;
        if(s[m]<=x){
            if(s[m]==x) pos=m;
            lo=m+1;
        }
        else hi=m-1;
    }
    return pos;
}

int pairs()
{
    int ans=0,low,upp;
    for(int i=1;i<=n;++i){
        low=lower(B-s[i],i+1,n);
        upp=upper(B-s[i],i+1,n);
        if (low>=0 && upp>=0) ans+=upp-low+1;
    }
    return ans;
}

int main()
{
    freopen("friends.inp","r",stdin);
    freopen("friends.out","w",stdout);
    ReadData();
    cout<<pairs();
    return 0;
}
