// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
//#define vll  vector<ll>
//#define vvll vector<vector<ll>>
//#define vpll vector<pair<ll, ll>>
#define v(a) vector<a>
#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

struct ev
{
    ll x, type, idx;
};


int main() {
    fastio;
    ll l, n, m, t1, t2, k = 0;
    cin >> l >> n >> m;
    v(ev) a;
    for(ll i = 0; i < n; i++) {
        cin >> t1 >> t2;
        a.push_back({t1, 1, 0});
        a.push_back({t2, 2, 0});
    }
    for(ll i = 0; i < m; i++) {
        cin >> t1;
        a.push_back({t1, 0, 1});
    }
    sort(a.begin(), a.end(), [](ev l, ev r){
        return (l.x < r.x || (l.x == r.x && l.type > r.type));
    });
    for(auto c:a) {
        cout << c.x << " " << c.type << " " << c.idx << "\n";
    }
    for(auto c:a) {
        if(c.idx == 1) {
            cout << k << "\n";
        }
        else {
            switch (c.type) {
                case 1:
                    k++;
                    break;
                case 2:
                    k--;
                    break;
            }
        }
    }

    cout << "\n";
    return 0;
}