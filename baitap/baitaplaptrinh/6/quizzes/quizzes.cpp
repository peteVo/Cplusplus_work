#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n, k, a[100001], placeholder[100001];

ll T(ll x, ll b[])
{
    for(int i = 1; i <= x; ++i) placeholder[i] = b[i];
    ll sum = 0;
    sort(placeholder + 1, placeholder + 1 + x);
    //for(int i = 1; i <= x; ++i) cout << "b[" << i <<"]: "<< b[i] << endl;
    //cout << "x: " << x;
    for(ll i = 1; i <= x; ++i){
        if(placeholder[i] <= sum + 1) sum += placeholder[i];
        else return sum;
    }
    return sum;
}

ll Solve()
{
    ll ans = -1;
    cin >> n >> k;
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
    }

    int cnt = 1;
    ll lo = 1, hi = n;
    while(lo <= hi){
        ll m = (lo + hi)/2;
        ll cache = T(m, a);
        //cout << "cache " << cnt << ": " << cache << ", key: " << m << endl;
        cnt++;
        if(cache == k) return m;
        if(cache > k){
            ans = m;
            hi = m-1;
        }
        else lo = m+1;
    }
    //cout << "T: " << T(2500, a) << ", k: " << k << endl;
    return ans;
}

int main()
{
    freopen("quizzes.inp", "r", stdin);
    freopen("quizzes.out", "w", stdout);

    ll t;
    cin >> t;
    for(ll i = 0; i < t; ++i){
        cout << Solve() << endl;
    }

    return 0;
}

