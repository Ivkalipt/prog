#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

constexpr ll INF = 1e18;

int main() {
    vector<string> a, b;
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    string s = "";
    for(char c : s1) {
        if('a' <= c && c <= 'z') s += c;
        else if('A' <= c && c <= 'Z') s += (c + 32);
        else {
            a.push_back(s);
            s = "";
        }
    }
    if(s != "") a.push_back(s);
    s = "";
    for(char c : s2) {
        if('a' <= c && c <= 'z') s += c;
        else if('A' <= c && c <= 'Z') s += (c + 32);
        else {
            b.push_back(s);
            s = "";
        }
    }
    if(s != "") b.push_back(s);
    s = "";
    set<string> a1(all(a)), b1(all(b)), res;
    for(string c : a1) if(b1.count(c)) res.insert(c);
    for(string c : res) cout << c << ' ';
    cout << '\n';

}
