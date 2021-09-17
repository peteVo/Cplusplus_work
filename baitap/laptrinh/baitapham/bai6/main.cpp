#include <iostream>
#include <cmath>

using namespace std;

int bai6(int r, int c, int R, int C)
{
    if ( double(c/r) > double(C/R) )
        return 1;
    else return 2;
}

int main()
{
    int r,c,R,C;
    cout<<"Nhap r1=";
    cin>>r;
    cout<<"\nNhap c1=";
    cin>>c;
    cout<<"\nNhap r1=";
    cin>>R;
    cout<<"\nNhap c2=";
    cin>>C;
    cout<<"Mua banh "<<bai6(r,c,R,C)<<" loi hon";
    return 0;
}
