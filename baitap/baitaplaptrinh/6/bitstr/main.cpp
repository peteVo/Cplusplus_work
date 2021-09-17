#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
/*
void Change(int index, string& s)
{
    for(int i = 0; i < 4; ++i){
        if(s[index + i] == '1') s[index + i] = '0';
        else s[index + i] = '1';
    }
}
*/

int Ans(string s, char indication)
{
    int ans = 0;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == indication){
            if(i > s.length() - 4){
                ans = -1;
                break;
            }
            for(int j = 0; j < 4; ++j){
                s[i + j] = (char)(1 - (s[i + j] - '0') + '0');
            }

            ans ++;
        }
        //cout << temp << endl;
    }
    return ans;
}

int MinChange(string s)
{
    int ans1 = Ans(s, '1');
    int ans2 = Ans(s, '0');

    if(ans1 == -1){
        return ans2;
    }
    else if(ans2 == -1) return ans1;
        else return min(ans1, ans2);
}

int main()
{
    freopen("bitstr.inp", "r", stdin);
    freopen("bitstr.out", "w", stdout);

    string s;
    cin >> s;

    cout << MinChange(s);

    return 0;
}
