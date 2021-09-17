#include <iostream>
#include <cmath>

using namespace std;

int bai1e(int n)
{
    double s = 1;
    while (n > 0)
    {
        s = s * n;
        n = n - 2;
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    cout<<bai1e(n);
    return 0;
}
