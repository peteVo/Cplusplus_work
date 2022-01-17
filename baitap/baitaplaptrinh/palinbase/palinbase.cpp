#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool is_palindrome(string s) {
    for(int i = 0, len = s.length(); i < len/2; ++i){
        if(s[i] != s[len-i-1]) return false;
    }
    return true;
}

string convert(int n, int base){
    string s = "";
    while(n > 0){
        int rem = n % base;
        n /= base;
        s.push_back(rem);
    }
    reverse(s.begin(), s.end());
    return s;
}

void Solve(int n)
{
    vector<int> val_bases;
    int num_bases = 0;
    for(int base = 2; base <= 16; base++){
        string s = convert(n, base);
        if(is_palindrome(s)){
            num_bases++;
            val_bases.push_back(base);
        }
    }

    if(num_bases > 0){
        cout << "YES ";
        for(int i = 0; i < num_bases; i++){
            cout << val_bases[i] << " ";
        }
        cout << "\n";
    }
    else cout <<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("palinbase.inp", "r", stdin);
    freopen("palinbase.out", "w", stdout);

    int x;
    while(cin >> x){
        if(x > 0){
            Solve(x);
        }
        else break;
    }

    return 0;
}
