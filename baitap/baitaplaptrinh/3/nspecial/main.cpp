#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

bool isPrime(int x)
{
    int y=sqrt(x);
    for(int i=2; i<=y; i++){
        if(x%i==0) return false;
    }
    return true;
}

int sumNum(int x)
{
    int cnt=0;
    while(x>0){
        cnt=cnt+x%10;
        x=x/10;
    }
    return cnt;
}

int sumPrime(int x)
{
    int div=2,cnt=0,y=sqrt(x);
    bool a=false;
    while(x>1){
        if(x%div==0){
            cnt=cnt+sumNum(div);
            x=x/div;
            a=true;
        }
        else div++;
    }
    if(a) return cnt;
    else return 0;
}


//int Solve(int n)
//{
//    bool flag=false;
//    while(flag==false){
//        n++;
//        if(!isPrime(n)){
//            if(sumNum(n)==sumPrime(n)){
//                flag=true;
//            }
//        }
//    }
//    return n;
//}

int Solve(int n)
{
    n++;
    while(1==1){
        if(sumNum(n)==sumPrime(n)) return n;
        else n++;
    }
}

int main()
{
    freopen("nspecial.inp","r",stdin);
    freopen("nspecial.out","w",stdout);
    int n;
    cin>>n;
    cout<<Solve(n);
    return 0;
}
