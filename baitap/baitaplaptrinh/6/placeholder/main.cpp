#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int n, p[100001];

int main()
{
    int swaps = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }

    bool flag = true;
    while(flag){
        flag = false;
        for(int i = 1; i < n; ++i){

            if(p[i]==i){
                swap(p[i],p[i+1]);
                flag = true;
                swaps++;
            }

        }
    }
    if(p[n]==n) swaps++;
    cout << swaps;
}
