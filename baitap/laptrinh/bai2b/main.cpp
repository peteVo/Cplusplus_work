#include <iostream>
#include <cmath>

using namespace std;

double bai2b(int n, double x)
{
    int i = 1, a = 1;
    double s = 1;
    while(i<=n)
    {
        a = a*i;
        s = s*x + 1.0/a;
        i++;
    }
    return s;
}

int main()
{
    int n;
    double x;
    cout<< "Nhap bien n: ";
    cin>>n;
    cout<<"\n";
    cout<< "Nhap bien x: ";
    cin>>x;
    cout<<"\n";
    cout<<bai2b(n, x);
    return 0;
}
