#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>

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

void BFS()
{
    bool isSolveable = false;
    queue<int> q;
    set<int> existed_remainder;
    //map<int, int> trace, prefix;
    int trace[1000001] = {0}, prefix[1000001] = {0};
    for(int i = 0; i < len; ++i){
        if(s[i] != '0') {
            int remainder = (s[i] - '0') % n;
            if(existed_remainder.find(remainder) == existed_remainder.end())
            {
                q.push(remainder);
                trace[remainder] = s[i] - '0';
                prefix[remainder] = 0;
                existed_remainder.insert(remainder);
            }
        }
    }

    while(!q.empty())
    {
        int x = q.front(); q.pop();
        int remainder = -1;
        for(int i = 0; i < len; ++i){
            remainder = (x * 10 + s[i] - '0') % n;
            if(existed_remainder.find(remainder) == existed_remainder.end()){
                q.push(remainder);
                trace[remainder] = s[i] - '0';
                prefix[remainder] = x;
                existed_remainder.insert(remainder);
                if(remainder == 0) break;
            }
        }
        if(remainder == 0) { isSolveable = true; break; }
    }

    if(!isSolveable) { cout << "0\n"; return; }
    int rem = 0;
    vector<int> ans;
    while(prefix[rem] != 0){
        ans.push_back(trace[rem]);
        rem = prefix[rem];
    }
    ans.push_back(trace[rem]);
    for(int i = ans.size() - 1; i >= 0; --i){
        cout << ans[i];
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("lm.inp", "r", stdin);
    freopen("lm.out", "w", stdout);

    ReadData();
    BFS();

    return 0;
}
