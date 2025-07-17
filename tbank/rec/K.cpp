// #pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc push_options
// #pragma gcc pop_options
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>
#include <set>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

void rec(ll k, map<ll, ll> & money, vll & cur) {
    if(k == 0) {
        cout << "Yes\n";
        cout << cur.size() << '\n';
        for(ll c : cur) cout << c << ' ';
        cout << '\n';
        exit(0);
    }
    if(k < 0) return;
    
    //for(ll c : cur) cout << c << ' ';
    for(auto c : money) {
        if(money[c.F] < 1) continue;
        money[c.F]--;
        cur.push_back(c.F);
        //cout << c << '!';
        rec(k - c.F, money, cur);
        money[c.F]++;
        cur.pop_back();
    }

}

int main() {
    ll n, k, t;
    cin >> n >> k;
    vll cur;
    map<ll, ll> money;
    for(ll i = 0; i < n; i++) {
        cin >> t;
        money[t] = 2;
    }
    //for(ll c : money) cout << c << ' ';
    rec(k, money, cur);
    cout << "No\n";
}

