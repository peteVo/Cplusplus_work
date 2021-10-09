#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int n;
int a[100001];
int startgcd[100001], endgcd[100001];

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

void Solve()
{
    // Making prefix gcd arr
    startgcd[1] = a[1];
    for(int i = 2; i <= n; ++i){
        startgcd[i] = (int)__gcd(a[i], startgcd[i-1]);
    }

    // Making suffix gcd arr
    endgcd[n] = a[n];
    for(int i = n - 1; i >= 2; --i){
        endgcd[i] = (int)__gcd(a[i], endgcd[i + 1]);
    }

    int pos = -1, maxPoint = -1;

    // If the number to be seleted is at the start or the end of the array
    // The gcd of the whole array will either be
    // -> endgcd[2] (when deleting the first number)
    // -> startgcd[n - 1] (when deleting the last number)
    if(endgcd[2] > maxPoint){
        maxPoint = endgcd[2];
        pos = 1;
    }
    if(startgcd[n - 1] > maxPoint){
        maxPoint = startgcd[n - 1];
        pos = n;
    }

    // Otherwise, if the element to be deleted is IN the array (not at the start nor the end)
    // the gcd of the array when the number at the i'th position would be
    // gcd(startgcd[i - 1], endgcd[i + 1])
    for(int i = 2; i < n; ++i){
        int g = (int)__gcd(startgcd[i - 1], endgcd[i + 1]);
        if(maxPoint < g){
            maxPoint = g;
            pos = i;
        }
    }
    cout << pos << " " << maxPoint << endl;
}

void Debug()
{
    for(int i = 1; i <= n; ++i) cout << a[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; ++i) cout << startgcd[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; ++i) cout << endgcd[i] << " ";
    cout << endl;
    cout << (int)__gcd(2, 4);
    return;
}

int main()
{
    freopen("gcd.inp", "r", stdin);
    freopen("gcd.out", "w", stdout);

    ReadData();
    Solve();

    return 0;
}
