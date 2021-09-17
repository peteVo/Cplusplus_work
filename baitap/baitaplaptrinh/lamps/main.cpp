#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int n;

struct bulb
{
    int bulbType;
    int numConsecutive = 1;
}c[1000001];
vector<bulb> lampfreq;

void ReadData()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> c[i].bulbType;
        if(i > 1 && c[i].bulbType == c[i-1].bulbType) c[i].numConsecutive = c[i-1].numConsecutive + 1;
    }
    //for(int i = 1; i <= n; ++i) cout << c[i].bulbType << " ";
    //cout << endl;
    //for(int i = 1; i <= n; ++i) cout << c[i].numConsecutive << " ";
}

void MakeLampFreq()
{
    for(int i = 2; i <= n; ++i){
        if(c[i].bulbType != c[i-1].bulbType) lampfreq.push_back(c[i-1]);
    }
    lampfreq.push_back(c[n]);
    //for(int i = 0; i < lampfreq.size(); ++i) cout << lampfreq[i].bulbType << " ";
    //cout << endl;
    //for(int i = 0; i < lampfreq.size(); ++i) cout << lampfreq[i].numConsecutive << " ";
    //cout << endl;
}

int MostConLamps()
{
    int cnt = 0;
    for(int i = 0; i < lampfreq.size(); ++i){
        if(lampfreq[i].numConsecutive == 1 && i > 0){
            cnt = max(cnt, lampfreq[i-1].numConsecutive + lampfreq[i+1].numConsecutive + 1);
        }
        cnt = max(cnt, lampfreq[i].numConsecutive+1);
    }
    return cnt;
}

int main()
{
    freopen("lamps.inp", "r", stdin);
    freopen("lamps.out", "w", stdout);

    ReadData();
    MakeLampFreq();
    cout << MostConLamps();

    return 0;
}
