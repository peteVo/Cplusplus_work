#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

void Try(int rem, int prev, int *prev_nums, int elements)
{
    if(rem == 0){
        for(int i = 1; i <= elements; ++i){
            cout << prev_nums[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = prev; i <= rem; ++i){
        prev_nums[elements+1] = i;
        Try(rem - i, i, prev_nums, elements+1);
    }
}

int main()
{
    freopen("analyse.inp", "r", stdin);
    freopen("analyse.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int prev_nums[51] = {0};
    int n; cin >> n;
    Try(n, 1, prev_nums, 0);

    return 0;
}
