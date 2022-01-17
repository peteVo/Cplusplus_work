#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n,x;
bool b[10000001]={false};

void ReadData()
{
    cin >> n;
    for(ll i = 1; i <= n; ++i){
        cin >> x;
        if(x <= 10000000) b[x]=true;
    }
}

ll minNum()
{
    ll i = 1;
    while(i <= 10000000){
        if(b[i] == false) return i;
        i++;
    }
    return 10000001;
}

int main()
{
    freopen("kmin.inp","r",stdin);
    freopen("kmin.out","w",stdout);

    ReadData();
    cout << minNum();

    return 0;
}
