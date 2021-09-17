#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

bool bai8i(int n)
{
    if (n<2)
        return false;
    int i=2, m = sqrt(n);
    while(i <= m)
    {
        if (n % i == 0)
            return false;
        i++;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    cout<<bai8i(n);
    return 0;
}
