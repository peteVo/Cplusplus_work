#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int alphabetx[26]={0}, alphabety[26]={0};

int changes(string s)
{
    if(s.size()%2!=0) return -1;
    int alphabetx[26]={0}, alphabety[26]={0},cnt=0;
    for(int i=0;i<s.size()/2;++i){
        ++alphabetx[s[i]-'a'];
    }
    for(int i=s.size()/2;i<s.size();++i){
        ++alphabety[s[i]-'a'];
    }
    for(int i=0;i<26;++i){
        cnt=cnt+abs(alphabetx[i]-alphabety[i]);

    }
    return (cnt+1)/2;
}

int main()
{
    freopen("anagram.inp","r",stdin);
    freopen("anagram.out","w",stdout);
    string s;
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>s;
        cout<<changes(s)<<"\n";
    }
    return 0;
}
