#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        cout<<x%k<<"\n";
    }
    return 0;
}
