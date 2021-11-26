#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;
stack<int> notes[7];

int n, p;
int s[500001], f[500001];

void ReadData()
{
    cin >> n >> p;
    for(int i = 1; i <= n; ++i){
        cin >> s[i] >> f[i];
    }
}

int Solve()
{
    int moves = 0;
    for(int i = 1; i <= n; ++i){
        if(notes[s[i]].empty() || notes[s[i]].top() < f[i]){
            notes[s[i]].push(f[i]);
            moves++;
        }
        else if(!notes[s[i]].empty() && notes[s[i]].top() > f[i]){
            while(!notes[s[i]].empty() && notes[s[i]].top() > f[i]){
                notes[s[i]].pop();
                moves++;
            }
            if(notes[s[i]].empty() || notes[s[i]].top() < f[i]){
                notes[s[i]].push(f[i]);
                moves++;
            }
        }
    }
    return moves;
}

int main()
{
    freopen("guitar.inp", "r", stdin);
    freopen("guitar.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
