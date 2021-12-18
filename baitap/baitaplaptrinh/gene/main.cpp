#include <iostream>
#include <cstdio>

using namespace std;

char a[1000001];
int n;

int Solve()
{
    int A = 0, T = 0, G = 0, X = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] == 'A') A++;
        else if(a[i] == 'T') T++;
        else if(a[i] == 'G') G++;
        else if(a[i] == 'X') X++;
    }
    A = T = G = X = A - n/4;
    int i = 0, j = 0;
    while(i < n && j < n){
        if(A != 0 || T != 0 || G != 0 || X != 0){
            if(a[j] == 'A') A++;
            else if(a[j] == 'T') T++;
            else if(a[j] == 'G') G++;
            else if(a[j] == 'X') X++;
            j++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("gene.inp", "r", stdin);
    freopen("gene.out", "w", stdout);

    string s;
    cin >> s;
    n = s.length()
    for(int i = 0; i < n; ++i){
        a[i] = s[i];
    }

    return 0;
}
