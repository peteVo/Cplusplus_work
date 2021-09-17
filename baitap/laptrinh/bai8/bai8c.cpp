#include <iostream>
#include <cmath>

using namespace std;

int bai8c(int n)
{
    int a = 0, b = n%10;
    int c = 0;
    while(n>9)
    {
        n = n/10;
        a = b;
        b = n%10;
        c = c + abs(a - b);
    }
    return c;
}

int main()
{
    int n;
    cin>>n;
    cout<<bai8c(n);
    return 0;
}
