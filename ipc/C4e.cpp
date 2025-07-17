// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC push_options
#pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define vp vector<pair<ll, ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

int main() {
    fastio;
    ll h, n, cnt = 0, t, mini = 5*10e5, s = 0;
    cin >> h >> n;
    vp a;
    cnt = n;
    for(ll i = 0; i < n; i++) {
        cin >> t;
        a.push_back({t-1, 0});
    }
    for(ll i = 0; i < n; i++) {
        cin >> t;
        a.push_back({h-t+1, 1});
    }
    sort(a.begin(), a.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
        return (a.F < b.F || (a.F == b.F && a.S < b.S));
    });
    /*for(auto c:a) {
        cout << c.F << " " << c.S << "\n";
    }*/
    for(auto c:a) {
        // cout << c.F << ' ' << c.S << '\n';
        if(c.S == 0) {
            cnt++;
            if(cnt < mini) {
                mini = cnt;
                s = 1;
            }
            else if(cnt == mini) s++;
        }
        else {
            cnt--;
            if(cnt == mini) s++;
        }
    }
    cout << mini << ' ' << s;
    cout << "\n";
    return 0;
}