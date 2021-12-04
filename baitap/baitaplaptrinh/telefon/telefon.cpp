#include <iostream>
#include <cstdio>
#include <cmath>
#include <deque>

using namespace std;

int Solve()
{
    deque<int> a;
    int x;
    int ans = 0;
    int n, d;
    int currentphones = 0;
    int currentlen = 0;
    cin >> n >> d;

    for(int i = 0 ; i < n; ++i){
        cin >> x;
        if(currentlen >= d){
            currentlen--;
            if(a.front() == 1) currentphones--;
            a.pop_front();
        }
        if(x == 1){
            a.push_back(x);
            currentphones++;
        }
        else{
            if(currentphones <= 0){
                a.push_back(1);
                currentphones++;
                ans++;
            }
            else{
                a.push_back(x);
            }
        }
        currentlen++;
    }
    return ans;
}

int main()
{
    freopen("telefon.inp", "r", stdin);
    freopen("telefon.out", "w", stdout);

    cout << Solve();

    return 0;
}
