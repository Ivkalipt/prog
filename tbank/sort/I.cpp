#include <algorithm>
#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

const ll inf = 1e9 + 7;

int main() {
    ll n;
    bool f = 0;
    cin >> n;
    string s, ans = "";
    cin >> s;
    map<char, ll> a;
    for(char c : s) {
        if(a.count(c)) a[c]++;
        else a[c] = 1;
    }
    string s1 = "", s2 = "";
    char x;
    for(pll c : a) {
        for(ll i = 1; i <= c.S / 2; i++) {
            s1 += c.F;
            s2 += c.F;
        }
        if(c.S & 1 && !f) {
            x = c.F;
            f = 1;
        }
    }
    reverse(all(s2));
    cout << s1;
    if(f) cout << x;
    cout << s2 << '\n';
}
