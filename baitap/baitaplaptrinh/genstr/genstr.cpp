#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int Factorial(int num)
{
    int ans = 1, i = 2;
    while(i<=num) ans *= i++;
    return ans;
}

void Solve()
{
    int cnt[26] = {0};

    string s; cin >> s; int len = s.length();
    char a[8];
    for(int i = 0, len = s.length(); i < len; ++i){
        a[i] = s[i];
        cnt[s[i]-'a']++;
    }
    sort(a, a + len);

    int num_str = Factorial(len);
    for(int i = 0; i < 26; ++i){
        num_str /= Factorial(cnt[i]);
    }
    cout << num_str << "\n";

    for(int i = 0; i < len; ++i) cout << a[i];
    cout << "\n";
    for(int i = 1; i <= num_str; ++i){
        if(next_permutation(a, a + len)){
            for(int i = 0; i < len; ++i) cout << a[i];
            cout << "\n";
        }
    }
}

int main()
{
    freopen("genstr.inp", "r", stdin);
    freopen("genstr.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();

    return 0;
}
