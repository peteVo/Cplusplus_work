#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    int swaps = 0;
    int n, p[100001];
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }

    for(int i = 1; i < n; ++i){
        if(p[i]==i) {
            for(int j = i; j <= n; ++j){
                if(p[j]!=i){
                    swap(p[i], p[i+1]);
                }
            }
            swaps++;
        }
    }
    cout << swaps;
}

