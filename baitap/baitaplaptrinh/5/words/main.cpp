#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    freopen("words.inp", "r", stdin);
    freopen("words.out", "w", stdout);

    string s;
    int maxLength = 0, cntStrings = 0;
    while(cin >> s){
        cntStrings++;
        int curLength = s.length();
        maxLength = max(maxLength, curLength);
    }

    cout << cntStrings << " " << maxLength;
    return 0;
}
