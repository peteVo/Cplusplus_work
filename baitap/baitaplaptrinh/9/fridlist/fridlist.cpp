#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;
bool f[51][51] = {false}, temp[51][51] = {false};
pair<int, int> connections[1226];

void ReadData()
{
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> connections[i].first >> connections[i].second;
        f[connections[i].first][connections[i].second] = true;
        f[connections[i].second][connections[i].first] = true;
        temp[connections[i].first][connections[i].second] = true;
        temp[connections[i].second][connections[i].first] = true;
    }
    for(int i = 1; i <= n; ++i) f[i][i] = true, temp[i][i] = true;
}

int MakeFriends()
{
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(f[i][j]){
                for(int k = 1; k <= n; ++k){
                    if(f[j][k] && !f[i][k] && !temp[i][k]){
                        cnt++;
                        temp[i][k] = true, temp[k][i] = true;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            f[i][j] = temp[i][j];
        }
    }
    return cnt;
}

void Solve()
{
    int cnt = 0;
    vector<int> ans;
    while(true){
        bool flag = false;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(!f[i][j]) flag = true;
        if(!flag) break;
        else{
            ans.push_back(MakeFriends());
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int i = 0, len = ans.size(); i < len; ++i){
        cout << ans[i] << endl;
    }
}

int main()
{
    freopen("fridlist.inp", "r", stdin);
    freopen("fridlist.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
