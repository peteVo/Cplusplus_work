#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n,t[100001];

void ReadData()
{
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>t[i];
}

void Solve()
{
    if(n==1){
        cout<<1<<" "<<0<<"\n";
        return;
    }
    ll i=1,j=n,m1=t[i],m2=t[j]*2;
    while(j-i>1){
        if(m1>m2){
            m2=m2+t[--j]*2;
        }
        else{
            m1=m1+t[++i];
        }
    }
    cout<<i<<" "<<n-j+1<<"\n";
}

/*
ll n,t[100001];

void ReadData()
{
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>t[i];
}

void Solve()
{
    ll i=1,j=n,m1=t[i],m2=t[n];
    bool halfcheckm1=false;
    while(j-i>1){
        if(m1>m2){
            j--;m2=m2+t[j];
        }
        else if(m1<m2){
                i++;
                if(t[i]%2==0){
                    m1=m1+t[i]/2;
                }
                else if(halfcheckm1){
                    m1=m1+1+t[i]/2;
                    halfcheckm1=false;
                }
                else{
                    m1=m1+t[i]/2;
                    halfcheckm1=true;
                }
            }
            else if(halfcheckm1){
                j--;
                m2=m2+t[j];
            }
            else if(j-i==2) i++;
            else {
                i++;
                j--;
                m2=m2+t[j];
                if(halfcheckm1 && t[i]%2!=0){
                    m1=m1+t[i]/2+1;
                    halfcheckm1=false;
                }
                else if(!halfcheckm1 && t[i]%2!=0){
                    m1=m1+t[i]/2;
                    halfcheckm1=true;
                }
                else m1=m1+t[i]/2;
            }
    }
    cout<<i<<" "<<n-j+1<<"\n";
}
*/
int main()
{
    freopen("distribution.inp","r",stdin);
    freopen("distribution.out","w",stdout);
    int test;
    cin>>test;
    for(int i=1;i<=test;++i){
        ReadData();
        Solve();
    }
    return 0;
}
