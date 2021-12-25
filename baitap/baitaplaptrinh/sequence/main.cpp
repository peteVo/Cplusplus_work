#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sequence.inp", "r", stdin);
    freopen("sequence.out", "w", stdout);

    ll n;
    cin >> n;
    ll i = 1, j = 1, k = 2;
    while(j + k < n){
        ll rem = i % k;
        i = k * k - rem + i;
        j += k, k++;
    }
    if(j < n){
        i = i + (k - (i % k));
        i += k*(n-j-1);
    }
    cout << i;

    return 0;
}
