#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, a[100001] = {0};

struct pii
{
    ll x,y;
}b[100001] = {0,0}, results[1000001];

bool tang(pii p, pii q)
{
    return( p.x < q.x || ( p.x == q.x && p.y < q.y)) ;
}

void ReadData()
{
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i].x = b[i-1].x + a[i];
        b[i].y = i;
    }
}

void LongestString()
{
    sort(b,b+1+n,tang);
    ll startPoint = 0, longest = 0, endPoint = 0, length = 0;
    for(ll i = 1; i <= n; ++i){
        if(b[i].x == b[i-1].x){
            length = b[i].y - b[startPoint].y;
            if(longest < length){
                longest = length;
                endPoint = b[i].y;
            }
        }
        else {
            startPoint = i;
        }

    }

    cout << endPoint - longest + 1 << " " << endPoint;
}

int main()
{
    freopen("szero.inp","r",stdin);
    freopen("szero.out","w",stdout);

    ReadData();

    LongestString();

    return 0;
}
