#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
ll n, k;
ll a[100001]; // The array
map<ll, ll> m; // Stores the frequency of each element in the array

void ReadData()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        m[a[i]]++;
    }
    sort(a + 1, a + 1 + n);
}

ll countSum(ll sum)
{
    ll cnt = 0;
    for(int i = 1; i <= n; ++i){
        int uppbnd = upper_bound(a + 1, a + 1 + n, sum - a[i]) - (a + i + 1); // Guaranteed to always find an answer
        if(uppbnd <= 0) break; // If not larger than 0 -> break
        //cout << "upper_bound = " << uppbnd << endl;
        cnt += uppbnd;
    }
    return cnt;
}

bool isValid(ll val) // Find out if the value val is valid as a solution
{
    for(int i = 1; i <= n; ++i){
        if(a[i] == val - a[i]){
            if(m.find(val - a[i]) != m.end() && m[a[i]] > 1) return true;
        }
        if(m.find(val - a[i]) != m.end() && m[val - a[i]] > 0){
            return true;
        }

    }
    return false;
}

ll Solve()
{
    ll lo = a[0] + a[1], hi = a[n-1] + a[n];
    while(lo <= hi){
        ll mi = (lo + hi)/2;
        ll cnt = countSum(mi);
        if(cnt >= k){
            hi = mi - 1;
        }
        else lo = mi + 1;
    }

    if(isValid(lo) && countSum(lo) >= k) return lo; // Check if lo is valid
    else return hi; // If lo is not valid -> then hi absolutely is ^^
}

int main()
{
    freopen("kthsum.inp", "r", stdin);
    freopen("kthsum.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
