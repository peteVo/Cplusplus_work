#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n, m, c[101], b[101], moneyInBox[101] = {0};

void ReadData()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> c[i] >> b[i];
    }
}

int maxPrice()
{
    for(int i = 1; i <= n; ++i){
        moneyInBox[b[i]] = max(moneyInBox[b[i]], c[i]);
    }
    int Price = 0;
    for(int i = 1; i <= m; ++i) Price+=moneyInBox[i];
    return Price;
}

int main()
{
    freopen("boxes.inp","r",stdin);
    freopen("boxes.out","w",stdout);
    ReadData();
    cout << maxPrice();
    return 0;
}
