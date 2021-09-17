#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;
string s1,s2;
ll c1[26]={0},c2[26]={0};
ll leastDelete()
{
    for(ll i=0; i<s1.length(); i++) c1[s1[i]-'a']++;
    for(ll i=0; i<s2.length(); i++) c2[s2[i]-'a']++;
    ll sum=0;
    for(ll i=0;i<26;++i){
        sum=sum+abs(c1[i]-c2[i]);
    }
    return sum;
}

int main()
{
    freopen("ad.inp","r",stdin);
    freopen("ad.out","w",stdout);
    cin>>s1>>s2;
    cout<<leastDelete();
    return 0;
}
