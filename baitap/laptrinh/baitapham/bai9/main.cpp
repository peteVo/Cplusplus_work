#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double bai9(double a, double b, int n)
{
    int i = 1;
    while (i<=n)
    {
        a = a*(1+b/100);
        i++;
    }
    return a;
}

int main()
{
    double a,b;
    int n;
    cout<<"Nhap chieu cao ban dau cua cay = ";
    cin>>a;
    cout<<"\nNhap muc tang tuong cua cay trong 1 ngay = ";
    cin>>b;
    cout<<"\nNhap so ngay cham soc cay = ";
    cin>>n;
    cout<<"Chieu cao cua cay sau "<<n<<" ngay = "<<setprecision(3)<<fixed<<bai9(a,b,n);
    return 0;
}
