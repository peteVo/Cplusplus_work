#include <iostream>
#include <cmath>

using namespace std;

double bai1f(int n)
{
    double s = 0;
    while(n>1)
    {
        s = 1/(n+s);
        n = n-1;
    }
    return s;
}
int main()
{
    int n;
    cin>>n;
    cout<<bai1f(n);
    return 0;
}
