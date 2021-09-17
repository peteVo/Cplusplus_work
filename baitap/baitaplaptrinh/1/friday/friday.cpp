#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int badDays(int n, int k)
{
    int ngay13=(k+12)%7, month=1;
    while(ngay13!=5 && month<=n){
        ngay13=(ngay13+30)%7;
        month++;
    }
    n-=month;
    int days=(n+6)/7;
    return days;
}

int main()
{
    freopen("friday.inp","r",stdin);
    freopen("friday.out","w",stdout);
    int n,k;
    cin>>n>>k;
    cout<<badDays(n,k);
    return 0;
}
