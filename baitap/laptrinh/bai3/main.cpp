#include <iostream>
#include <cmath>

int bai3(int n)
{
    int a = 0;
    int b = 0;
    while (b<=n)
    {
        a = a + 1;
        b = b+ sqrt(a);
    }
    return a-1;
}

using namespace std;

int main()
{
    int n;
    cin>>n;
    cout <<bai3(n);
    return 0;
}
