#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int b[1000001] = {-1}, a[1000001] = {0};

void arrayB(int *ptr)
{
    for(int i = 1; i <= *ptr; ++i){
        for(int j = i + 1; j <= *ptr; ++j){
            if(a[j] > a[i]) {b[i] = j; break;}
        }
        if(b[i] == 0) b[i] = -1;
    }
    for(int i = 1; i <= *ptr; ++i) cout << b[i] << " ";
}

void ReadData()
{
    int i = 1;
    while(cin >> a[i]){
        i++;
    }
    int n = i-1;
    arrayB(&n);
}

int main()
{
    freopen( "jfs.inp" , "r" , stdin );
    freopen( "jfs.out" , "w" , stdout );

    ReadData();

    return 0;
}
