#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

string s;
ll n, len;

void ReadData()
{
    cin >> n >> s;
    len = s.length();
    sort(s.begin(), s.end());
}

int MOD(string x)
{
    ll m = 0;
    for(int i = 0, j = x.length(); i < j; ++i){
        m = (m * 10 + x[i] - '0') % n;
    }
    return m;
}

int BFS()
{
    queue<int> q;
    set<int> existed_remainder;
    map<int, int> trace, prefix;
    for(int i = 0; i < len; ++i){
        if(s[i] != '0') {
            q.push((s[i] - '0') % n);
            trace[(s[i] - '0') % n] = s[i] - '0';
            pre[(s[i] - '0') % n] = 0;
        }
    }
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        if(remainder == 0) return x;
        if(existed_remainder.find(remainder) == existed_remainder.end()){
            existed_remainder.insert(remainder);
            for(int i = 0; i < len; ++i){
                int y = (x * 10 + s[i] - '0') % n;
                q.push(y);
                trace
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("lm.inp", "r", stdin);
    freopen("lm.out", "w", stdout);

    ReadData();
    cout << BFS();

    return 0;
}
