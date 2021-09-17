#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int month[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int KC(int d1,int m1,int y1,int d2,int m2,int y2)
{
    int ans=0;
    if(y1==y2)
    {
        if(m1==m2) ans=ans+d2-d1+1;
        else
        {
            ans=ans+month[m1]-d1+1+d2;
            if((y1%4==0 && y1%100!=0) || y1%400==0) ans++;
            else
            {
                ans=ans+month[m1]-d1+1+d2;
                for(int t=m1+1;t<=m2-1;++t)
                {
                    ans=ans+month[t];
                    if(t==2 && ((y1%4==0 && y1%100!=0) || y1%400==0)) ++ans;
                }
            }
        }
    }
    else
    {
        ans=ans+KC(d1,m1,y1,31,12,y1)+KC(1,1,y2,d2,m2,y2);
        for(int t=y1+1;t<=y2-1;++t){
            ans=ans+365;
            if((t%4==0 && t%100!=0) || t%400==0) ans++;
        }
    }
    return ans;
}

int main()
{
    freopen("numdays.inp","r",stdin);
    freopen("numdays.out","w",stdout);
    int d1,d2,m1,m2,y1,y2;
    cin>>d1>>m1>>y1>>d2>>m2>>y2;
    cout<<KC(d1,d2,m1,m2,y1,y2);
    return 0;
}
