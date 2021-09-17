#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int bai8h(int n)
{
    int i = 0;
    int a = 1;
    while (a <= n)
    {
        if ((n%a)==0)
            i = i + 1;
        a++;
    }
    return i;
}

int main()
{
    int n;
    cin>>n;
    cout<<bai8h(n);
    return 0;
}
