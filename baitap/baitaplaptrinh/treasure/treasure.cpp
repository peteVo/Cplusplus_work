#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, k;
ll a[1002][1002] = {0};
bool visited[1002][1002] = {false};
ll dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

void ReadData()
{
    cin >> n >> k;
    for(ll i = 1; i <= n; ++i){
        ll x, y, p; cin >> x >> y >> p;
        a[x][y] = p;
    }
}

ll DFS(ll x, ll y)
{
    ll res = (ll)a[x][y];
    visited[x][y] = true;
    for(ll i = 0; i < 4; ++i){
        ll u = x + dx[i], v = y + dy[i];
        if(u < 0 || v < 0) continue;
        if(!visited[u][v] && a[u][v] != 0) res += DFS(u, v);
    }
    return res;
}

ll Solve()
{
    vector<ll> ans;
    for(ll r = 1; r <= 1000; ++r){
        for(ll c = 1; c <= 1000; ++c){
            if(!visited[r][c] && a[r][c] != 0){
                ans.push_back(DFS(r, c));
            }
        }
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    ll res = 0;
    k = min(k, (ll)ans.size());
    for(ll i = 0; i < k; ++i)
        res += ans[i];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("treasure.inp", "r", stdin);
    freopen("treasure.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
