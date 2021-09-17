#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

void bai8k(int n)
{
     int dem;
     for(int i = 2; i <= n; i++){
        dem = 0;
        while(n % i == 0){
            ++dem;
            n /= i;
        }
        if(dem){
            cout << i;
            if(dem > 1) cout << "^" << dem;
            if(n > i){
                cout << " * ";
            }
        }
     }
}

int main()
{
    int n;
    cin>>n;
    bai8k(n);
    return 0;
}
