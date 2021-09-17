#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

string s;
int k;
int color[26] = {0};

void ReadData()
{
    cin >> s;
    cin >> k;
}

int SmallestString()
{
    int n = s.length();
    int i = 0, j = 0;
    int colors = 0, minLen = 100000;

    while(i < n){
        while(colors < k && j < n){
            if(color[s[j] - 'a'] == 0){
                colors++;
            }
            color[s[j] - 'a']++;
            j++;
        }

        minLen = min(minLen, j - i);
        if(color[s[i] - 'a'] == 1){
            colors--;
        }
        color[s[i] - 'a']--;
        i++;
    }
    return minLen;
}

int main()
{
    freopen("beads.inp", "r", stdin);
    freopen("beads.out", "w", stdout);

    ReadData();

    cout << SmallestString();

    return 0;
}
