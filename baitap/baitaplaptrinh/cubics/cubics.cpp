#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
int n, k;
ll a[100001];

typedef pair<ll, ll> pii;
pii s[100001];

bool tang(pii x, pii y)
{
    return (x.first < y.first || (x.first == y.first && x.second < y.second));
}

void ReadData()
{
    s[0].first = s[0].second = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i] = a[i] - k;
        s[i].first = s[i-1].first + a[i];
        s[i].second = i;
    }
    sort(s+1, s+1+n, tang);
}

void Cubics()
{
    //for(int i = 1; i <= n; ++i) cout << a[i] << endl;
    //for(int i = 1; i <= n; ++i) cout << "s[" << i << "].first: " << s[i].first << endl << "s[" << i << "].second: " << s[i].second << endl;
    int minPos = 1e6;
    int minLen = 1e6;
    for(int i = 1; i <= n; ++i){
        if(s[i].first == s[i-1].first){
            if(s[i-1].second < minPos){
                minPos = s[i-1].second+1;
                minLen = s[i].second - s[i-1].second;
            }
        }
    }
    if(minPos == 1e6) cout << 0;
    else cout << minLen << " " << minPos << endl;
    return;
}

int main()
{
    freopen("cubics.inp", "r", stdin);
    freopen("cubics.out", "w", stdout);

    ReadData();
    Cubics();

    return 0;
}
