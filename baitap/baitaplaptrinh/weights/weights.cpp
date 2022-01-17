#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef unsigned long long ll;
const ll INF = 1e18;

void Solve(ll n)
{
    vector<ll> a;
    while(n > 0){
        a.push_back(n % 3);
        n /= 3;
    }

    ll len = a.size();
    vector<ll> power1, power2;
    for(int i = 0; i < len; ++i){
        if(a[i] == 1)
            power1.push_back(i);
        if(a[i] == 2){
            power2.push_back(i);
            if(i == len - 1) {a.push_back(1); len++;}
            else a[i+1]++;
        }
        if(a[i] == 3){
            if(i == len - 1) {a.push_back(1); len++;}
            else a[i+1]++;
        }
    }

    for(int i = 0, l = power1.size(); i < l; ++i)
        cout << power1[i] << " ";
    cout << "\n";
    for(int i = 0, l = power2.size(); i < l; ++i)
        cout << power2[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("weights.inp", "r", stdin);
    freopen("weights.out", "w", stdout);

    ll n; cin >> n;
    Solve(n);

    return 0;
}
