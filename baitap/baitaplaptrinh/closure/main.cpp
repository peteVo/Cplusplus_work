#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
int a[1000001];
int s[100001] = {0};

int Solve()
{
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(s[a[i]] == 0) s[a[i]] = i;
        else {
            int closure = i - s[a[i]] + 1;
            ans = max(ans, closure);
        }
    }
    return ans;
}

int main()
{
    freopen("closure.inp", "r", stdin);
    freopen("closure.out", "w", stdout);

    cout << Solve();

    return 0;
}
