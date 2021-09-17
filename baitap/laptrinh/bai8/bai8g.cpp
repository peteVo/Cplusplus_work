#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

bool bai8g(int n)
{
    int i = 9;
    while (n>0)
    {
        if (i>=(n % 10))
            i = n %10;
        else return false;
        n = n / 10;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    if (bai8g(n)==true)
        cout<<"cac chu so cua n co thu tu tang dan tu trai sang phai";
    else cout<<"cac chu so cua n ko co thu tu tang dan tu trai sang phai";
    return 0;
}
