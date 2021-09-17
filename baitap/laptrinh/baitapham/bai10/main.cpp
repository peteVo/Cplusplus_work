#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int Prime)
{
    if (Prime<2)
        return false;
    int m = sqrt(Prime), i=2;
    while (i<=m)
    {
        if (Prime % i == 0)
            return false;
        i++;
    }
    return true;
}

void bai10(int n)
{
    int Prime = 2, x = 1;
    while (x<=n)
    {
        if (isPrime(Prime)){
            cout<<Prime<<"\n";
            Prime++;
            x++;
        }
        else Prime++;
    }
}

int main()
{
    int n;
    cout<<"Nhap n = ";
    cin>>n;
    bai10(n);
    return 0;
}
