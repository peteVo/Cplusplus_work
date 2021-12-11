#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <list>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int maxpos = 0, maxval = 0;
int n;
list<int> a;
vector<pii> prev_ans;
int maxnum = 0, maxindex = 0;

void ReadData()
{
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a.push_back(x);
        if(x > maxval){
            maxval = x;
            maxpos = i + 1;
        }
    }
}

void SubSolve()
{
    for(int i = 0; i < n; ++i){
        if(a.)
    }
}

void Solve(ll k)
{
    if(k <= maxindex){
        cout << p[k] << " " << p[k+1] << endl;
        return;
    }
    k -= maxindex;
    k = (k - 1) % (n - 1) + 1;
    cout << maxindex << " " << a[k] << endl;
}

int main()
{
    freopen("coders.inp", "r", stdin);
    freopen("coders.out", "w", stdout);

    ReadData();
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; ++i){
        ll k;
        cin >> k;
        Solve(k);
    }

    return 0;
}
