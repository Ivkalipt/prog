// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>
#include <cstdio>

#define ll long long
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
    fastio;
    freopen("dictionary.in", "r", stdin);
    //freopen("dictionary.out", "w", stdout);
    string t, val = "1";
    map<string, set<string>> a;
    while(cin >> val) {
        cin >> t;
        //cout << t << ' ';
        cin >> t;
        while(t.back() == ',') {
            t.pop_back();
            a[t].insert(val);
            cin >> t;
        }
        a[t].insert(val);
    }

    //cout << '\n';
    cout << a.size() << '\n';
    for(auto &c : a) {
        cout << c.F << " - ";
        for(auto it{c.S.begin()}; it != c.S.end(); it++) {
            cout << *it;
            if(it != --c.S.end()) {
                cout << ", ";
            }
        }
        cout << '\n';
    }
}
