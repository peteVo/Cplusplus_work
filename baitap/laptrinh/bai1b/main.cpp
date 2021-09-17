#include <iostream>
#include <cmath>

using namespace std;

double bai1b(int n)
{
    int i = 2;
    double S = 0;
    while(i<=n)
    {
        S = S + (double)(i-1)/i;
        i++;
    }
    return S;
}

int main()
{
    int n;
    cin>>n;
    cout<<bai1b(n);
    return 0;
}
