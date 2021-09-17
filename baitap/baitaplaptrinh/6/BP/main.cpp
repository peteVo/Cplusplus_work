#include <iostream>
#include <cstdio>

using namespace std;

void HOANVIDEP(int n)
{
    //Special case -> 1
    if(n == 1) {
        cout << "1";
        return;
    }

    //Special case -> no solution
    if(n <= 3){
        cout << "NO SOLUTION";
        return;
    }

    //Special case -> n = 4
    if(n == 4){
        cout << "2 4 1 3";
        return;
    }

    //Normal case
    for(int i = 1; i <= n; i+=2){
        cout << i << " ";
    }
    for(int i = 2; i < n; i+=2){
        cout << i << " ";
    }
}

int main()
{
    freopen("BP.inp", "r", stdin);
    freopen("BP.out", "w", stdout);

    int n;
    cin >> n;
    HOANVIDEP(n);

    return 0;
}
