#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int len = s.length();
    int curLen = 0, maxLen = 0;
    string temp = "";
    map<char, bool> m;
    for(int i = 0; i < len; ++i){
        map<char, bool>::iterator it = m.find(s[i]);
        while(it != m.end()){
            m.erase(temp[0]);
            temp.erase(0, 1);
            curLen -= 1;
            it = m.find(s[i]);
        }
        m[s[i]] = true;
        curLen++;
        temp.push_back(s[i]);
        maxLen = max(maxLen, curLen);
    }
    return maxLen;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb");
}
