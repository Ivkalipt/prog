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

 int main() {
    string s;
    cin >> s;
    bool f = 0;
    string res = "";
    for(ll i = 0; i < s.size(); i++) {
        if(s[i] == '\\' || s[i] == ':') {
            res = "", f = 1;
            continue;
        }
        if(s[i] == '.') break;
        res.push_back(s[i]);


    }
    cout << res << '\n';
}


