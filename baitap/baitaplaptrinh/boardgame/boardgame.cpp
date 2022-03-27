#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll st[100000001] = {0};

void Prep()
{
    ll i = 1, j = 1, stage = 1;
    while(j <= 100000000){
        if(j <= i){
            st[j++] = stage;
        }
        else{
            ++stage, i += stage;
        }
    }
    //st[99991011] = 14141;
    //for(ll i = 1; i <= 28; ++i) cout << i << " -> " << st[i] << "\n";
}

ll Stage(ll n)
{
    if(n <= 100000000) return st[n];
    else {
        ll stage = 14141, i = 99991011; n -= i;
        while(n > stage){
            n -= stage++;
        }
        return stage;
    }
}

ll Solve(ll k, string s)
{
    ll points = k;
    ll stage = Stage(k), len = s.length(), cur_len = 0;
    while(cur_len < len){
        bool flag = false;
        if(s[cur_len] == 'N'){
            ll placeholder_k = k, placeholder_stage = stage;
            if(s[cur_len+1] == 'W') placeholder_k -= stage;
            else placeholder_k -= stage - 1;
            placeholder_stage--;
            if(Stage(placeholder_k) == placeholder_stage){
                k = placeholder_k, stage = placeholder_stage;
                flag = true;
            }
        }
        else if(s[cur_len] == 'S'){
            ll placeholder_k = k, placeholder_stage = stage;
            if(s[cur_len+1] == 'W') placeholder_k += stage;
            else placeholder_k += stage + 1;
            placeholder_stage++;
            if(Stage(placeholder_k) == placeholder_stage){
                k = placeholder_k, stage = placeholder_stage;
                flag = true;
            }
        }
        else if(s[cur_len] == 'W'){
            if(Stage(k-1) == stage) k--, flag = true;
        }
        else{
            if(Stage(k+1) == stage) k++, flag = true;
        }
        cur_len += 2;
        if(flag) points += k;
    }
    return points;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("boardgame.inp", "r", stdin);
    freopen("boardgame.out", "w", stdout);

    Prep();
    ll k; string s; cin >> k; cin >> s;
    cout << Solve(k, s);

    return 0;
}
