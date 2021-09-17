#include <iostream>
#include <cmath>

using namespace std;

double bai1a(int n)
{
    double s = 0;
    int i = 1;
    while (i <= n)
    {
        s = s + sqrt(i);
        i = i + 1;
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    cout<<bai1a(n);
    return 0;
}
