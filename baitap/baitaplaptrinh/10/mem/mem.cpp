#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int parse(string s)
{
    if(s[0] == '?') return -1;
    int res = 0;
    for(int i = 0, len = s.length(); i < len; i++){
        res = res * 10 + s[i] - '0';
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("mem.inp", "r", stdin);
    freopen("mem.out", "w", stdout);

    int q; cin >> q;
    bool occupied[1000000] = {false};
    int iterator = 0;

    string temp; int n;
    for(int i = 0; i < q; ++i){
        cin >> temp;
        n = parse(temp);
        if(n == -1){
            while(occupied[iterator]) iterator++;
            occupied[iterator] = true;
            cout << iterator << "\n";
        }
        else if(n < (int)1e6) occupied[n] = true;
    }

    return 0;
}
