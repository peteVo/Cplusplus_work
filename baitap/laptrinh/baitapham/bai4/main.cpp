#include <iostream>
#include <cmath>

using namespace std;

bool bai4(double a, double b, double R)
{
    if ( a >= 2*R && b >= 2*R )
        return true;
    else return false;
}

int main()
{
    double a, b, R;
    cout<<"Nhap a=";
    cin>>a;
    cout<<"\nNhap b=";
    cin>>b;
    cout<<"\nNhap R=";
    cin>>R;
    if (bai4(a,b,R))
        cout<<"YES";
    else cout<<"NO";
    return 0;
}
