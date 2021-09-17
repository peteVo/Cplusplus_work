#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int vach[10]={6,2,5,5,4,5,6,3,7,6};

int soVach(int h,int m)
{
    int cnt=0;
    cnt=cnt+vach[h%10]+vach[m%10];
    h=h/10;
    m=m/10;
    cnt=cnt+vach[h%10]+vach[m%10];
    return cnt;
}

void Answer(int n)
{
    for(int h=0; h<24; ++h){
        for(int m=0; m<59; ++m){
            if(soVach(h,m)==n){
                if(h<10) cout<<"0"<<h<<":";
                else cout<<h<<":";
                if(m<10) cout<<"0"<<m;
                else cout<<m;
                return;
            }
        }
    }
    cout<<"Impossible";
}

int main()
{
    freopen("alarm.inp","r",stdin);
    freopen("alarm.out","w",stdout);
    int n;
    cin>>n;
    Answer(n);
    return 0;
}
