#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int parse(char c)
{
    if(c >= '0' && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

void Solve()
{
    string s; cin >> s;
    int n = s.length();

    int sum_digits = 0;
    int min_base = 2;
    for(int i = 0; i < n; ++i){
        int p = parse(s[i]);
        min_base = max(min_base, p + 1);
        sum_digits += p;
    }

    for(int base = min_base; base <= 36; ++base){
        if(sum_digits % (base - 1) == 0){
            cout << base << "\n";
            return;
        }
    }
    cout << "No solution.\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("kbased.inp", "r", stdin);
    freopen("kbased.out", "w", stdout);

    Solve();

    return 0;
}
