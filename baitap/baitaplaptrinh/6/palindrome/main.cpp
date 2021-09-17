#include <iostream>
#include <cstdio>
#include <vector>
#define maxPal 1000000

typedef long long ll;
using namespace std;
ll PalGen(ll digits, ll multiplier, ll remaining);

ll Palindrome(ll n)
{
    ll currentNum = 9;
    ll k = 0;
    ll i = 1;

    while(n > currentNum)
    {
        n -= currentNum;
        i++;

        if((i-1)/2 > k)
        {
            currentNum *= 10;
            k++;
        }

        //cout << n << endl;
    }
    //cout << n << endl;

    ll gen = PalGen(i, currentNum/9, n-1);

    return gen;
}

ll PalGen(ll digits, ll multiplier, ll remaining)
{
    ll lefthalf = multiplier + remaining;
    ll righthalf = lefthalf;
    ll i;
    if(digits % 2 != 0){
        i = digits / 2;
        righthalf /= 10;
    }
    else i = digits / 2;
    for(ll j = 0; j < i; j++){
        lefthalf = lefthalf*10 + righthalf%10;
        righthalf/=10;
    }
    return lefthalf;
}

int main()
{
    freopen("palindrome.inp", "r", stdin);
    freopen("palindrome.out", "w", stdout);

    ll n;
    cin >> n;

    cout << Palindrome(n);

    return 0;
}
