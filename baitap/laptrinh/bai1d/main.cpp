#include <iostream>
#include <cmath>

using namespace std;

double bai1d(int n)
{
    int i = 1;
    double s = 0;
    while (i<=n)
    {
        s = sqrt(2.0 + s);
        i = i + 1;
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    cout<<bai1d(n);
    return 0;
}
