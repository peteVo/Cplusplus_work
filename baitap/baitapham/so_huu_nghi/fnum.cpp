#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int TU(int x)
{
    int Sum=0, Div, y=sqrt(x);
    for(Div=2;  Div<=y; ++Div){
        if(x%Div==0){
            if (Div == x/Div) Sum+=Div;
            else Sum = Sum + Div + x/Div;
        }
    }
    return Sum;
}

void sohuunghi(int n)
{
    int a,b,c;
    bool isTrue = true;
    for (a=1;a<n;++a){
        b = TU(a);
        if (b<=n && a<=b){
            c = TU(b);
            if (a==c){
                cout<<a<<" "<<b<<"\n";
                isTrue = false;
            }
        }
    }
    if (isTrue)
        cout<<"-1";
}

int main()
{
    freopen("fnum.inp","r",stdin);
    freopen("fnum.out","w",stdout);
    int n;
    cin>>n;
    sohuunghi(n);
    return 0;
}
