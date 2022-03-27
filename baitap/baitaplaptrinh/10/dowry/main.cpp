#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

int n, a[21], total = 0, avg;
vi x(21);
int s[4] = {0};
vvi ans;

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        {cin >> a[i]; total += a[i];}
    avg = total/3;
}

void Try(int i)
{
    for(int v = 1; v <= 3; ++v){
        if(s[v] + a[i] <= avg){
            s[v] += a[i];
            x[i] = v;

            if(i == n){
                if(s[1] == s[2] && s[2] == s[3]) ans.push_back(x);
            }
            else Try(i + 1);

            s[v] -= a[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("dowry.inp", "r", stdin);
    freopen("dowry.out", "w", stdout);

    ReadData();
    if(total % 3 != 0) {cout << "-1\n"; return 0;}

    Try(1);

    if(ans.size() <= 0) {cout << "-1"; return 0;}

    cout << ans.size() << "\n";
    for(int i = 0, len = ans.size(); i < len; ++i){
        for(int j = 1; j <= n; ++j){
            cout << (char)('A' + ans[i][j] - 1);
        }
        cout << "\n";
    }

    return 0;
}
