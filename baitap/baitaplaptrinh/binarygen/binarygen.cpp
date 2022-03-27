#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

void Solve()
{
    int n; string s;
    cin >> n >> s;
    bool flag = false;
    for(int i = n-1; i >= 0; --i){
        if(s[i] == '1')
            s[i] = '0';
        else{
            s[i] = '1';
            flag = 1;
            break;
        }
    }
    if(flag)
        cout << s << "\n";
    else cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("binarygen.inp", "r", stdin);
    freopen("binarygen.out", "w", stdout);

    Solve();

    return 0;
}
