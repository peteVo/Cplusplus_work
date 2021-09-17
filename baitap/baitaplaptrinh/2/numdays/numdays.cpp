#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int month[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

long long daysOneYear(int d1,int d2,int m1,int m2,int y1,int y2)
{
    if( (y1%4==0 && y1%100!=0) || y1%400==0) month[2]=29;
    int s=0;
    if(m1=m2) s=d2-d1+1;
    else{
        s=s+month[m1]-d1+1;
        for(int i=m1+1; i<m2; ++i) s+=month[i];
        s=s+d2;
        month[2]=28;
    }
    return s;
}

int days(int d1,int d2,int m1,int m2,int y1,int y2)
{
    int s=0;
    if(y1==y2) s=daysOneYear(d1,d2,m1,m2,y1,y2);
    else {
        s=s+daysOneYear(d1,31,m1,12,y1,y1);
        for(int i=y1+1;i<y2;++i){
            if( (i%4==0 && i%100!=0) || i%400==0) s+=366;
            else s+=365;
        }
        s=s+daysOneYear(1,d2,1,m2,y2,y2);
    }
    return s;
}

int main()
{
    freopen("numdays.inp","r",stdin);
    freopen("numdays.out","w",stdout);
    int d1,d2,m1,m2,y1,y2;
    cin>>d1>>m1>>y1>>d2>>m2>>y2;
    cout<<days(d1,d2,m1,m2,y1,y2);
    return 0;
}
