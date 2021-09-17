#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int freq[26] = {0};
string s;

void ReadStr()
{
    char constVal = 'a';
    for(int i = 0; i < s.length(); ++i){
        freq[s[i] - constVal]++;
    }
}

bool isValid(int removeIndex)
{
    freq[removeIndex] -= 1;
    int minF = 100000, maxF = 0;
    for(int i = 0; i < 26; ++i){
        if(freq[i] != 0) {
            minF = min(minF, freq[i]), maxF = max(maxF, freq[i]);
        }
    }
    freq[removeIndex] += 1;
    if(minF == maxF) return true;
    return false;
}

bool Solve()
{
    int minF = 100000, maxF = 0;
    for(int i = 0; i < 26; ++i){
        if(freq[i] > 0) {
            minF = min(minF, freq[i]), maxF = max(maxF, freq[i]);
        }
    }
    if(minF == maxF) return true;
    for(int i = 0; i < 26; ++i){
        if(isValid(i)) return true;
    }
    return false;
}

int main()
{
    freopen("validstr.inp", "r", stdin);
    freopen("validstr.out", "w", stdout);

    cin >> s;
    ReadStr();
    if(Solve()) cout << "YES";
    else cout << "NO";
    //for(int i =0; i < 26; ++i) cout << "freq[" << i << "] : " << freq[i] << endl;


    return 0;
}
