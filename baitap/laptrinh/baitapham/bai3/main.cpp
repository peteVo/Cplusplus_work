#include <iostream>
#include <cmath>

using namespace std;

void bai3(int a, int b)
{
    int x = b - 2*a;
    if ( x > 0)
        cout<<"sau "<<x<<" nam nua";
    else cout<<"cach day "<<abs(x)<<" nam";
}

int main()
{
    int a, b;
    cout<<"nhap a= ";
    cin>>a;
    cout<<"\nnhap b= ";
    cin>>b;
    bai3(a,b);
    return 0;
}
