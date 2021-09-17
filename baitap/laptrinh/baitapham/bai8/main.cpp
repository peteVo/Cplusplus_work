#include <iostream>
#include <cmath>

using namespace std;

int bai8(int a,int n)
{
    int Days = 0, Multiplier = 1;
    while ( n > Multiplier*a)
    {
        Days++;
        Multiplier*=2;
    }
    return Days;
}

int main()
{
    int a,n;
    cout<<"Nhap so te bao san co = ";
    cin>>a;
    cout<<"\nNhap so te bao can = ";
    cin>>n;
    cout<<"\nSo ngay can nuoi cay = "<<bai8(a,n);
    return 0;
}
