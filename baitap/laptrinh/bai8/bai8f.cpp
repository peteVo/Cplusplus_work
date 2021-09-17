#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

bool bai8f(int n)
{
    int s = 0, i = n;
    while (i>0)
    {
        s = 10*s + (i%10);
        i /= 10;
    }
    if (s == n)
        return true;
    else return false;
}

int main()
{
    int n;
    cin>>n;
    if (bai8f(n)==true)
        cout<<"n la so doi xung";
    else cout<<"n khong la so doi xung";
    return 0;
}
