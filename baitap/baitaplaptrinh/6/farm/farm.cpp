#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

//typedef
typedef pair<int, int> pii;

// variables
int m, n;
int chickens = 0, foxes = 0;
char a[1000][1000];
bool mark[1000][1000] = {false};

//constants
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

bool ValidCell(int x, int y)
{
    return (x >= 0 && x < m && y >= 0 && y < n);
}

void ReadData()
{
    cin >> m >> n;
    string s;
    for(int i = 0; i < m; ++i){
        cin >> s;
        for(int j = 0; j < n; ++j){
            a[i][j] = s[j];
            if(s[j] == 'c') chickens++;
            if(s[j] == 'f') foxes++;
        }
    }
}

void BFS(int r, int c)
{
    queue<pii> Q;
    int chic = 0, fox = 0;
    if(a[r][c] == 'c') chic++;
    else if (a[r][c] == 'f') fox++;
    Q.push(pii(r, c));
    mark[r][c] = true;
    int res = 0;

    while(!Q.empty()){
        r = Q.front().first, c = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; ++i){
            int x = r + dr[i];
            int y = c + dc[i];

            if(ValidCell(x, y) && !mark[x][y] && a[x][y]!='#'){
                if(a[x][y] == 'c') chic++;
                else if (a[x][y] == 'f') fox++;
                Q.push(pii(x, y));
                mark[x][y] = true;
            }
        }
    }
    if(fox >= chic) chickens-=chic;
    else foxes-=fox;
}

void RemainingChickensAndFoxes()
{
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(!mark[i][j]) BFS(i, j);
        }
    }
    cout << foxes << " " << chickens;
}

int main()
{
    freopen("farm.inp", "r", stdin);
    freopen("farm.out", "w", stdout);

    ReadData();
    RemainingChickensAndFoxes();

    return 0;
}
