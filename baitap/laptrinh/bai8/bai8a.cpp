#include <iostream>
#include <cmath>

using namespace std;

int bai8a(int n)
{
    int s = 0;
    while(n>0)
    {
        s++;
        n = n/10;
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    cout<<bai8a(n);
    return 0;
}
