#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n;
string s;
char a[101];
int cnt[3] = {0};

void ReadData()
{
    cin >> n;
    cin >> s;
    for(int i = 1; i <= n; ++i){
        if(s[i-1] == 'X') cnt[0]++;
        if(s[i-1] == 'T') cnt[1]++;
        if(s[i-1] == 'D') cnt[2]++;
        a[i] = s[i-1];
    }
}

void PrintString()
{
    for(int i = 1; i <= n; ++i) cout << a[i];
}

int Solve()
{
    int X = cnt[0], T = cnt[1], D = cnt[2];
    int swps = 0;
    for(int i = 1; i <= X; ++i){
        if(a[i] != 'X'){
            bool flag = false;
            if(a[i] == 'D'){
                for(int j = X + T + 1; j <= n; ++j){
                    if(a[j] == 'X'){
                        swap(a[i], a[j]);
                        swps++;
                        //cout << "swapped " << i << " with " << j << " -> Current string: "; PrintString(); cout << endl;
                        flag = true;
                        break;
                    }
                }
            }
            if(flag == false){
                for(int j = X + 1; j <= n; ++j){
                    if(a[j] == 'X'){
                        swap(a[i], a[j]);
                        swps++;
                        //cout << "swapped " << i << " with " << j << " -> Current string: "; PrintString(); cout << endl;
                        break;
                    }
                }
            }
        }
    }

    for(int i = X + 1; i <= X + T; ++i){
        if(a[i] != 'T'){
            for(int j = X + T + 1; j <= n; ++j){
                if(a[j] == 'T'){
                    swap(a[i], a[j]);
                    //cout << "swapped " << i << " with " << j << " -> Current string: "; PrintString(); cout << endl;
                    swps++;
                    break;
                }
            }
        }
    }

    return swps;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("marbles.inp", "r", stdin);
    freopen("marbles.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
