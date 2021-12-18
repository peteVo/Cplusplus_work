#include <iostream>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;

int mod(string s, int n)
{
    int remainder = 0;
    for(int i = 0, len = s.length(); i < len; ++i){
        remainder = remainder * 10 + (s[i] - '0');
        remainder %= n;
    }
    return remainder;
}

string BFS(int n)
{
    queue<string> q;
    set<int> seen_remainder;
    string s = "1";
    q.push(s);
    while(!q.empty()){
        s = q.front(); q.pop();
        int remainder = mod(s, n);
        if(remainder == 0)
            return s;
        if(seen_remainder.find(remainder) == seen_remainder.end()){
            seen_remainder.insert(remainder);
            q.push(s + "0");
            q.push(s + "1");
        }
    }
    return "0";
}

int main()
{
    freopen("multiple.inp", "r", stdin);
    freopen("multiple.out", "w", stdout);

    int n;
    while(cin >> n){
        if(n == 0) break;
        cout << BFS(n) << endl;
    }

    return 0;
}
