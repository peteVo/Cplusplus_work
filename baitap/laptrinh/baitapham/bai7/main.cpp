#include <iostream>
#include <cmath>

using namespace std;

void bai7(int a, int b, int c)
{
    int x = 0, y;
    while ( x<=(c/a) )
    {
        if ( ((c-a*x)%b) == 0){
            y = (c-a*x)/b;
            cout<<x<<" "<<y<<"\n";
        }
        x++;
    }
}

int main()
{
    int a,b,c;
    cout<<"Nhap a=";
    cin>>a;
    cout<<"\nNhap b=";
    cin>>b;
    cout<<"\nNhap c=";
    cin>>c;
    bai7(a,b,c);
    return 0;
}
