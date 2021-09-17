#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char eval[2][3] = {{'8', '7', '9'}, {'6', '4', '5'}};

string decodedNum(string s)
{
    int n = s.length()-1;
    int i = n;
    string ans = "";

    while(i >= 0){
        if(s[i] == 'a')
            ans = '1' + ans;

        else if(s[i] == 'b')
            ans = '2' + ans;

        else if(s[i] == 'c'){
            if(i > 0 && s[i-1] == 'c'){ //check if i >= 1
                ans = '3' + ans;
                i--;
            }
            else{
                if(i > 1){ //check if i >= 2
                    ans = eval[s[i-1]-'a'][s[i-2]-'a'] + ans;
                    i-=2;
                }
                else return "-1";
            }

        }
        else return "-1";
        i--;
    }
    return ans;
}

int main()
{
    freopen("decode.inp", "r", stdin);
    freopen("decode.out", "w", stdout);

    string s;
    cin >> s;
    cout << decodedNum(s);

    return 0;
}
