#include <iostream>
#include <cstdio>
#include <vector>
#include <list>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void Solve()
{
    ll maxnum = -1, maxpos = -1;
    ll n; cin >> n;
    vector<ll> p(n);
    for(int i = 0; i < n; ++i) {
        cin >> p[i];
        if(p[i] > maxnum)
            maxnum = p[i], maxpos = i;
    }

    vector<pii> saved_pairs;

    list<ll>::iterator it0, it1;
    list<ll> l(p.begin(), p.end());
    for(int i = 0; i < maxpos; ++i){
        it1 = l.begin(); it0 = it1++;
        saved_pairs.push_back(pii(*it0, *it1));
        if(*it0 > *it1) {
            ll val = *it1;
            l.erase(it1); l.push_back(val);
        }
        else{
            ll val = *it0;
            l.erase(it0); l.push_back(val);
        }
    }

    vector<ll> ans(l.begin(), l.end());

    ll Q, k; cin >> Q;
    for(;Q > 0; Q--){
        cin >> k;
        if(k <= maxpos)
            cout << saved_pairs[k - 1].first << " " << saved_pairs[k - 1].second << "\n";
        else
            cout << ans[0] << " " << ans[(k-maxpos-1)%(n-1) + 1] << "\n";
    }

    //for(vector<pii>::iterator it = saved_pairs.begin(); it != saved_pairs.end(); it++){
    //    cout << it->first << " " << it->second << endl;
    //}
    //for(vector<ll>::iterator it = ans.begin(); it != ans.end(); it++){
    //    cout << *it << " ";
    //}
}

int main()
{
    freopen("coders.inp", "r", stdin);
    freopen("coders.out", "w", stdout);

    Solve();

    return 0;
}
