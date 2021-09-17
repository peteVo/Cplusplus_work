#include <iostream>
#include <cmath>

using namespace std;

bool bai5(int a, int b, int c, int d)
{
    if ( a >= c && a >= d)
    {
        if ( b >= c || b >= d )
            return true;
    }
    if ( a >= c )
    {
        if ( b >= d )
            return true;
    }
    if ( a >= d )
    {
        if ( b >= c )
            return true;
    }
    return false;
}

int main()
{
    int a, b, c ,d;
    cout<<"Nhap a1=";
    cin>>a;
    cout<<"\nNhap b1=";
    cin>>b;
    cout<<"\nNhap a2=";
    cin>>c;
    cout<<"\nNhap d2=";
    cin>>d;
    if (bai5(a,b,c,d))
        cout<<"YES";
    else cout<<"NO";
    return 0;
}
