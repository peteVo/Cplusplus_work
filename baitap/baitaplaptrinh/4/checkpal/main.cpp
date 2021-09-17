#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int alphabets[26]={0};

void check(string s)
{
    for(int i=0;i<s.size();++i){
        ++alphabets[s[i]-'a'];
    }
    for(int i=0;i<26;++i){
        if(alphabets[i]%2!=0){
            for(int j=i+1;j<26;++j){
                if(alphabets[j]%2!=0){
                    cout<<"NO";
                    return;
                }
            }
        }
    }
    cout<<"YES";
}

int main()
{
    freopen("checkpal.inp","r",stdin);
    freopen("checkpal.out","w",stdout);
    string s;
    cin>>s;
    check(s);
    return 0;
}
