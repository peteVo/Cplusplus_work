#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int bai8e(int n)
{
    int i = -1;
    while (n>0)
    {
        if (n%2==0)
        {
            if ((n%10)>i)
                i = n%10;
        }
        n = n/10;
    }
    return i;
}

int main()
{
    int n;
    cin>>n;
    cout<<bai8e(n);
    return 0;
}
