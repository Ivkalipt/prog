#include <unordered_map>
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

const ll inf = 1e9 + 7;

int main() {
    unordered_map<string, string> a{
        {"1010", "a"},
        {"010000", "b"},
        {"00100", "c"},
        {"00101", "d"},
        {"011", "e"},
        {"100100", "f"},
        {"110100", "g"},
        {"10011", "h"},
        {"1011", "i"},
        {"010011110", "j"},
        {"0100110", "k"},
        {"11011", "l"},
        {"00011", "m"},
        {"0101", "n"},
        {"1000", "o"},
        {"110101", "p"},
        {"0100111110", "q"},
        {"0011", "r"},
        {"0000", "s"},
        {"1100", "t"},
        {"00010", "u"},
        {"010010", "v"},
        {"010001", "w"},
        {"01001110", "x"},
        {"100101", "y"},
        {"0100111111", "z"},
        {"111", "_"}
    };
    string s;
    cin >> s;
    ll n = s.size();
    string ans = "", cur = "";
    for(ll i = 0; i < n; i++) {
        cur.push_back(s[i]);
        if(a.count(cur)) {
            ans += a[cur];
            cur = "";
        }
    }
    if(!cur.empty()) cout << "incorrect" << '\n';
    else cout << ans;

}
