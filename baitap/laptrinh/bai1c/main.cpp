#include <iostream>
#include <cmath>

using namespace std;

double bai1c(int n)
{
    double S = 0;
    int i = 1;
    int a = 1;
    while (i <= n)
    {
        a = a * i;
        S = S + 1.0/a;
        i = i + 1;
    }
    return S;
}

int main()
{
    int n;
    cin>>n;
    cout<<bai1c(n);
    return 0;
}
