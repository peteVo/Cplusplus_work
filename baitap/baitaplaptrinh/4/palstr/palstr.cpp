#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

char alpha[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','S','Y','Z'};
int alphabets[26]={0};

void palindrome(string s)
{
    int i,cnt=0,check=-1;
    for(i=0;i<s.size();++i){
        alphabets[s[i]-'A']++;
    }
    for(i=0;i<26;++i){
        if(alphabets[i]%2!=0){
            check=i;
            for(int j=i+1;j<26;++j){
                if(alphabets[j]%2!=0){
                    cout<<"NO SOLUTION";
                    return;
                }
            }
        }
    }
    if(check==-1){
        for(i=0;i<26;++i){
            for(int j=1;j<=alphabets[i]/2;++j) cout<<alpha[i];
        }
        for(i=25;i>=0;--i){
            for(int j=1;j<=alphabets[i]/2;++j) cout<<alpha[i];
        }
    }
    else {
        for(i=0;i<26;++i){
            if(i!=check){
                for(int j=1;j<=alphabets[i]/2;++j) cout<<alpha[i];
            }
        }
        for(int j=1;j<=alphabets[check];++j) cout<<alpha[check];
        for(i=25;i>=0;--i){
            if(i!=check){
                for(int j=1;j<=alphabets[i]/2;++j) cout<<alpha[i];
            }
        }
    }
}

int main()
{
    freopen("palstr.inp","r",stdin);
    freopen("palstr.out","w",stdout);
    string s;
    cin>>s;
    palindrome(s);
    return 0;
}
