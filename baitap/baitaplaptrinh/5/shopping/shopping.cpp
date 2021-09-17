#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int convert(string s)
{
    /*
    string end_of_line = "";
    for(int i = s.length() - 1; i >= 0; ++i){
        if((char)s[i] == (char)' ') break;
        else end_of_line = s[i] + end_of_line;
    }
    */

    int i = s.length() - 1; // last character
    while (i != 0 && !isspace(s[i]))
    {
      --i;
    }
    string end_of_line = s.substr(i+1); // +1 to skip leading space;

    if(end_of_line == "mot" || end_of_line == "Mot" || end_of_line == "mOt" || end_of_line == "moT" || end_of_line == "MOt" || end_of_line == "mOT"
       || end_of_line == "MOT" || end_of_line == "1" || end_of_line == "MoT") return 1;

    if(end_of_line == "hai" || end_of_line == "Hai" || end_of_line == "hAi" || end_of_line == "haI" || end_of_line == "HAi" || end_of_line == "hAI"
       || end_of_line == "HAI" || end_of_line == "2" || end_of_line == "HaI") return 2;

    if(end_of_line == "ba" || end_of_line == "Ba" || end_of_line == "bA" || end_of_line == "BA" || end_of_line == "3") return 3;

    if(end_of_line == "bon" || end_of_line == "Bon" || end_of_line == "bOn" || end_of_line == "boN" || end_of_line == "BOn" || end_of_line == "bON"
       || end_of_line == "BON" || end_of_line == "4" || end_of_line == "BoN") return 4;

    if(end_of_line == "nam" || end_of_line == "Nam" || end_of_line == "nAm" || end_of_line == "naM" || end_of_line == "NAm" || end_of_line == "nAM"
       || end_of_line == "NAM" || end_of_line == "5" || end_of_line == "NaM") return 5;

    if(end_of_line == "sau" || end_of_line == "Sau" || end_of_line == "sAu" || end_of_line == "saU" || end_of_line == "SAu" || end_of_line == "sAU"
       || end_of_line == "SAU" || end_of_line == "6" || end_of_line == "SaU") return 6;

    if(end_of_line == "bay" || end_of_line == "Bay" || end_of_line == "bAy" || end_of_line == "baY" || end_of_line == "BAy" || end_of_line == "bAY"
       || end_of_line == "BAY" || end_of_line == "7" || end_of_line == "BaY") return 7;

    if(end_of_line == "tam" || end_of_line == "Tam" || end_of_line == "tAm" || end_of_line == "taM" || end_of_line == "TAm" || end_of_line == "tAM"
       || end_of_line == "TAM" || end_of_line == "8" || end_of_line == "TaM") return 8;

    if(end_of_line == "chin" || end_of_line == "Chin" || end_of_line == "cHin" || end_of_line == "chIn" || end_of_line == "chiN"
       || end_of_line == "CHin" || end_of_line == "cHIn" || end_of_line == "chIN" || end_of_line == "ChIn" || end_of_line == "ChiN"
       || end_of_line == "cHiN" || end_of_line == "CHIn" || end_of_line == "cHIN" || end_of_line == "CHiN" || end_of_line == "ChIN"
       || end_of_line == "9") return 9;
}

int FindRawSum()
{
    string num;
    getline(cin, num);
    int n;
    n = stoi(num);
    int rawSum = 0;

    for(int i = 1; i <= n; ++i){
        string s;
        getline(cin, s);
        //cout << s << endl;
        //cout << convert(s) << endl;
        rawSum += convert(s);
    }

    return rawSum;
}

double Solve()
{
    double rawSum = FindRawSum(), rawResult = rawSum;
    double promo = 0,  cnt = 0;
    if(rawSum >= 21){
        while(rawSum > 0){
            (rawSum >= 7) ? cnt = cnt + 7 * (100 - promo) / 100 : cnt = cnt + rawSum * (100 - promo) / 100;
            if(promo < 50) promo += 10;
            rawSum -= 7;
        }
        cout << rawResult << " " << cnt;
    }
    else{
        cout << rawResult << " " << rawSum;
    }
}

int main()
{
    //freopen("shopping.inp", "r", stdin);
    //freopen("shopping.out", "w", stdout);

    Solve();

    return 0;
}
