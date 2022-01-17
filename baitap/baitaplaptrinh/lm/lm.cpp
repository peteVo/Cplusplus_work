#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>

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

string BFS()
{
    queue<string> q;
    set<int> existed_remainder;
    for(int i = 0; i < len; ++i){
        if(s[i] != '0') q.push(string(1, s[i]));
    }
    while(!q.empty())
    {
        string x = q.front(); q.pop();
        int remainder = MOD(x);
        if(!remainder) return x;
        if(existed_remainder.find(remainder) == existed_remainder.end()){
            existed_remainder.insert(remainder);
            for(int i = 0; i < len; ++i){
                string y = x; y += s[i];
                q.push(y);
            }
        }
    }
    return "0";
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
