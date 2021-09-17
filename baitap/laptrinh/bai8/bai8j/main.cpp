#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

void bai8j(int n)
{
    int largeDigit=0, largeDigitNum=0;
    while (n>0)
    {
        if (largeDigit <= n%10)
        {
            if (largeDigit = n%10)
                largeDigitNum++;
            else {
                    largeDigit = n%10;
                    largeDigitNum = 1;
            }
        }
        n = n / 10;
    }
    cout<<"Chu so lon nhat: "<<largeDigit<<"\n";
    cout<<"So luong chu so lon nhat: "<<largeDigitNum;
}

int main()
{
    int n;
    cin>>n;
    bai8j(n);
    return 0;
}
