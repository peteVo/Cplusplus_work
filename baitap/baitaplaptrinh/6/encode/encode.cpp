#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

/*char table[11][11];
int m, n;

void PutStuffInTableAndPrintThem(string s);

void Encode(string s)
{
    int len = s.length();
    //cout << len;
    int sqlen = sqrt(len);
    if(sqlen * sqlen == len){
        m = n = sqlen;
        PutStuffInTableAndPrintThem(s);
        return;
    }
    else{
        n = sqlen;
        m = n + 1;
        PutStuffInTableAndPrintThem(s);
        return;
    }
    cout << 1;
}

void PutStuffInTableAndPrintThem(string s)
{
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            table[i][j] = s[cnt++];
        }
    }
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cout << table[j][i];
        }
        cout << " ";
    }
    return;
}*/

char t[100][100];
int r,c;
string s = "";

void ReadData()
{
    string holder;
    while(cin >> holder){
        s += holder;
    }
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            t[i][j] = ' ';
        }
    }
}

void Encode()
{
    int n = s.length();
    int m = sqrt(n);
    r = c = m;
    if(r*c < n) ++c;
    if(r*c < n) ++r;
    int cnt = 0;

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            t[i][j] = s[cnt++];
        }
    }

    /*for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            cout<<t[i][j];
        }
        cout << endl;
    }*/
    for(int j = 0; j < c; ++j){
        for(int i = 0; i < r; ++i){
            if(i*c + j < n){ // Check if t[i][j] is available
                cout << t[i][j];
            }
        }
        cout << " ";
    }
    //cout << "c = " << c << endl;
    //cout << "r = " << r << endl;
}

int main()
{
    freopen("encode.inp", "r", stdin);
    freopen("encode.out", "w", stdout);

    ReadData();
    Encode();
    //cout << s;

    return 0;
}
