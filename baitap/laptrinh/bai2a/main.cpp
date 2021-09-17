#include <iostream>
#include <cmath>

using namespace std;

double bai2a(int n, double x)
{
    int i = 1, a = 1;
    double s = 0, b = 1;
    while (i <= n)
    {
        a = a*i;
        b = b*x;
        if (i % 2 == 0)
            s = s - b/a;
        else s = s + b/a;
        i = i + 1;
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
    cout<<bai2a(n, x);
    return 0;
}
