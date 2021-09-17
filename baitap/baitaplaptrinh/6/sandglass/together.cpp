#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ll N, a[100001];
    ll freq[100001]={0};
    ll combine[100001];
    ll maxValue = -1;
    cin>>N;
    for(ll i = 1; i<=N; ++i){
        cin>>a[i];
    }
    sort(a + 1, a + 1 + N);

    for(ll i = 1; i<=100000; ++i){
        freq[a[i]]++;
    }
    maxValue = freq[0]+freq[1];
    for(int i = 1; i < 100000; ++i){
        maxValue = max(maxValue, freq[i-1]+freq[i]+freq[i+1]);
    }
    maxValue = max(maxValue, freq[100000-1]+freq[100000]);
}

