#include <iostream>
#include <cmath>

using namespace std;

int bai8b(int n)
{
    int s = 0;
    while(n>0)
    {
        s = 10*s + (n%10);
        n = n / 10;
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    cout<<bai8b(n);
    return 0;
}
