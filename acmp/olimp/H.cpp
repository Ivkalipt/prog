// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll unsigned long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

int main() {
    string s1;
    cin >> s1;
    v(char) s(all(s1));
    unordered_map<char, ll> a;
    for(char c : s) {
        if(a.count(c)) {
            a[c]++;
        }
        else {
            a[c] = 0;
        }
    }
    char end = s[0];
    ll k = 1;
    for(ll i = 1; i < s.size(); i++) {
        if(s[i] == end) {
            k++;
        }
        else {
            k = 1;
        }
        if(k == 3) {
            a[s[i]]--;
            for(auto [x, y] : a) {
                if(y <= s.size() / 2 && s[i] != x) {
                    s[i] = x;
                    a[x]++;
                    break;
                }
            }
            k = 2;
        }
        cout << k << '\n';
    }
    for(char c : s) {
        cout << c;
    }
    cout << '\n';
}
