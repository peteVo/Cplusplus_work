#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

int a[1000001], n, x;

int Uoc()
{
    int dem=0;
    cin>>n>>x;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
        if(a[i]!=0){
            if(x%a[i]==0) ++dem;
        }
    }
    return dem;
}

int main()
{
    freopen("mang01.inp","r",stdin);
    freopen("mang01.out","w",stdout);
    cout<<Uoc();
    return 0;
}
