#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;
int alphas1[26]={0}, alphas2[26]={0};

int difference(string s1, string s2)
{
    int i;
    for(i=0;i<s1.size();++i){
        ++alphas1[s1[i]-'a'];
    }
    for(i=0;i<s2.size();++i){
        ++alphas2[s2[i]-'a'];
    }
    int cnt=0;
    for(int i=0;i<26;++i){
        cnt=cnt+abs(alphas1[i]-alphas2[i]);
    }
    return cnt;
}

int main()
{
    freopen("anadel.inp","r",stdin);
    freopen("anadel.out","w",stdout);
    string s1, s2;
    cin>>s1>>s2;
    cout<<difference(s1,s2);
    return 0;
}
