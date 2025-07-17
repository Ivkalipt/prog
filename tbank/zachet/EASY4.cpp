#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define ld long double
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

const ll inf = 1e9 + 7;

int main() {
    fastio;
    ll q;
    cin >> q;
    vll a = {0}, p = {0};
    while(q--) {
        string q1;
        cin >> q1;
        if(q1[0] == '+') {
            a.push_back(stoi(q1.substr(1, q1.size() - 1)));
            p.push_back(a.back() + p.back());
        }
        else if(q1[0] == '-') {
            cout << a.back() << '\n';
            a.pop_back(), p.pop_back();
        }
        else if(q1[0] == '?') {
            cout << p.back() - p[p.size() - stoi(q1.substr(1, q1.size() - 1)) - 1] << '\n';
        }
    }


}

