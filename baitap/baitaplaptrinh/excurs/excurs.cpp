#include <iostream>
#include <cstdio>
#include <map>
#include <deque>
#include <cmath>

using namespace std;

int k, n;
int a[100001];

void ReadData()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

int Solve()
{
    deque<int> dq;
    int len = 0, bestcity = 0, beststartingpoint = 0, currentcity = 0;
    map<int, int> m;

    map<int, int>::iterator e = m.end();
    for(int i = 1; i <= n; ++i){
        map<int, int>::iterator it = m.find(a[i]);
        if(it == e || it->second <= 0){
            currentcity++;
        }
        m[a[i]]++;
        len++;
        dq.push_back(a[i]);

        if(len > k){
            int x = dq.front();
            dq.pop_front();
            len--;
            if(m[x] <= 1){
                currentcity--;
            }
            m[x]--;
        }

        if(bestcity <= currentcity){
            bestcity = currentcity;
            beststartingpoint = max(1, i - len + 1);
        }
    }
    return beststartingpoint;
}

int main()
{
    freopen("excurs.inp", "r", stdin);
    freopen("excurs.out", "w", stdout);

    ReadData();
    cout << Solve();

    return 0;
}
