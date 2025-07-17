#pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize ("Ofast")

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

const ll inf = 1e9 + 1;

int main() {
    ll t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        if(s[0] > s[2]) cout << s[0] << '>' << s[2] << '\n';
        else if(s[0] < s[2]) cout << s[0] << '<' << s[2] << '\n';
        else cout << s[0] << '=' << s[2] << '\n';
    }
}
