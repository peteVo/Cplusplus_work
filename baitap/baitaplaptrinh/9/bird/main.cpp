#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int n;
char m[12][100002];
bool visited[12][100002] = {false};
vector<int> ans;

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= 10; ++i){
        string s; cin >> s;
        for(int j = 0; j < n; ++j){
            m[i][j] = s[j];
        }
    }
}

void DFS(int r, int c, vector<int> moves)
{
    moves.push_back(r);
    visited[r][c] = true;
    if(c >= n-1) { ans = moves; return; }
    int lo = max(r - 1, 1), hi = min(r + 1, 10);
    if(m[lo][c+1] != 'X' && !visited[lo][c+1])
        DFS(lo, c+1, moves);
    if(m[hi][c+1] != 'X' && !visited[hi][c+1])
        DFS(hi, c+1, moves);
}

int main()
{

    freopen("bird.inp", "r", stdin);
    freopen("bird.out", "w", stdout);

    ReadData();
    vector<int> temp;
    DFS(10, 0, temp);
    /*
    for(int i = 0; i < ans.size(); ++i){
        m[ans[i]][i] = '*';
    }
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= 10; ++i){
        for(int j = 0; j < n; ++j){
            cout << m[i][j];
        }
        cout << endl;
    }
    */
    int p = 0;
    pair<int, int> current = pair<int, int>(0, 0);
    vector<pair<int, int> > res;
    for(int i = 0; i < n - 1; ++i){
        if(ans[i] > ans[i+1] || (ans[i] == ans[i+1] && ans[i] == 1)){
            current.second++;
        }
        else{
            if(!current.second){
                current.first = i + 1;
                continue;
            }
            res.push_back(current);
            current = pair<int, int>(i + 1, 0);
            p++;
        }
    }
    cout << p << endl;
    for(int i = 0, len = res.size(); i < len; ++i){
        cout << res[i].first << " " << res[i].second << endl;
    }

    return 0;
}
