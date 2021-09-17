#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;
string s;
ll n;

ll numA()
{
    cin>>s;
    cin>>n;
    ll ss=s.size(), acnt=0, sum, leftover=n%s.size();
    for(ll i=0;i<ss;++i){
        if(s[i]=='a') acnt++;
    }
    sum=acnt*(n/ss);
    for(ll i=0;i<leftover;++i)
        if(s[i]=='a') sum++;
    return sum;

}

int main()
{
    freopen("repstr.inp","r",stdin);
    freopen("repstr.out","w",stdout);
    cout<<numA();
    return 0;
}
