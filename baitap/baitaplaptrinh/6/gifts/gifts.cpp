#include <iostream>
#include <cstdio>
#include <algorithm>

//initialize stuff
using namespace std;
typedef long long ll;

//variables
ll IDs[5001], n;// TBCs[25000001], m;

/*
void MakeTBCArray()
{
    ll counter = 1;
    for(ll i = 1; i <= n; ++i){
        for(ll j = i + 1; j <= n; ++j){
            TBCs[counter++] = (IDs[i] + IDs[j]);//Keep in mind TBCs are doubled
        }
    }
    m = counter - 1;
}

ll Prizes()
{
    sort(IDs + 1, IDs + 1 + n);
    sort(TBCs + 1, TBCs + 1 + m);

    ll cnt = 0, i = 1, j = 1;
    while(i <= n && j <= m){
        if(IDs[i] * 2 == TBCs[j]){
            cnt++;
            i++;
            j++;
        }
        else if(IDs[i] * 2 > TBCs[j]){
            j++;
        }
        else i++;
    }
    return cnt;
}
*/

void ReadData()
{
    ll x, i = 1;
    while(cin >> x){
        IDs[i++] = x;
    }
    n = i - 1;
    sort(IDs + 1, IDs + 1 + n);
}

int Prizes()
{
    int cnt = 0;
    for(int m = 2; m < n; ++m){
        int i = 1, j = n;
        while(i < j){
            if(IDs[i] + IDs[j] == 2 * IDs[m]){
                cnt++;
                break;
            }
            else if(IDs[i] + IDs[j] < 2 * IDs[m]) i++;
            else j--;
        }
    }
    return cnt;
}

int main()
{
    freopen("gifts.inp", "r", stdin);
    freopen("gifts.out", "w", stdout);

    ReadData();

    cout << Prizes();

    return 0;
}
