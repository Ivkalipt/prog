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

ll mod = 1e9 + 7;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        s.pop_back();
        s.pop_back();
        s.push_back('i');
        cout << s << '\n';
    }
}
