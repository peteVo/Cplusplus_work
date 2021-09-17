#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int fold(int a,int b)
{
    if(a<b) return 1e8;
    int cnt=0;
    while(a>b){
        a=(a+1)/2;
        ++cnt;
    }
    return cnt;
}

int foldingTimes(int W, int H, int w, int h)
{
    int dem1=fold(W,w)+fold(H,h), dem2=fold(H,w)+fold(W,h);
    int kq=min(dem1,dem2);
    if(kq>=1e8) return -1;
    else return kq;
}

int main()
{
    freopen("folding.inp","r",stdin);
    freopen("folding.out","w",stdout);
    int W,H,w,h;
    cin>>W>>H>>w>>h;
    cout<<foldingTimes(W,H,w,h);
    return 0;
}
