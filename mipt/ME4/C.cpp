#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

int main() {
    string s;
    cin >> s;
    ll q, m = s.size();
    cin >> q;
    vpll pref(m + 1, {0, 0});
    for(ll i = 0; i < m; i++) {
       pref[i + 1] = {pref[i].F + (s[i] == '('), pref[i].S + (s[i] == ')')}; 
    }
    for(ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        if(pref[r].F - pref[l - 1].F == pref[r].S - pref[l - 1].S) cout << "Yes\n";
        else cout << "No\n";
    }
}
