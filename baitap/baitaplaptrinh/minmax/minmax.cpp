#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void Solve()
{
    string a, b; cin >> a >> b;
    int n = a.length(), m = b.length();
    int i = 0, j = 0;

    //min
    i = 0, j = 0;
    while(i < n || j < m){
        if(i < n && a[i] < b[j])
            cout << a[i++];
        else
            cout << b[j++];
    }
    cout << "\n";

    //max
    i = 0, j = 0;
    while(i < n || j < m){
        if(i < n && a[i] > b[j])
            cout << a[i++];
        else
            cout << b[j++];
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("minmax.inp", "r", stdin);
    freopen("minmax.out", "w", stdout);

    Solve();

    return 0;
}
