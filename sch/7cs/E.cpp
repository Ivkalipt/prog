#include <sstream>
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
    ll n;
    string w1, w2;
    bool f;
    cin >> n >> f;
    map<string, string> a;
    for(ll i = 0; i < n; i++) {
        cin >> w1 >> w2;
        if(f) a[w2] = w1;
        else a[w1] = w2;
    }
    cin.ignore();
    string phrase;
    getline(cin, phrase);
    // cout << phrase << '\n';
    ll cnt = 0;
    for(char c : phrase) cnt += (c == ' ');
    stringstream words(phrase);
    for(ll i = 0; i <= cnt; i++) {
        words >> w1;
        if(a.count(w1)) cout << a[w1] << ' ';
        else cout << "? ";
    }
}

