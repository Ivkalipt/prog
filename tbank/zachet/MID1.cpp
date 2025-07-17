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
    ll n, k, l = 0, l1, r1, mini = inf;
    cin >> n >> k;
    vll a(n);
    for(ll & c : a) cin >> c;
    vll b(25e4 + 1, 0);
    unordered_set<ll> notnull;
    for(ll i = 0; i < n; i++) {
        ll c = a[i];
        if(b.empty()) b[c]++, notnull.insert(c);
        else {
            b[c]++, notnull.insert(c);
            if(c == a[l]) {
                while(b[a[l]] > 1) {
                    b[a[l]]--;
                    l++;
                }
            }
        }
        /*for(ll v : b) cout << v << ' ';
        cout << '\n';*/
        if(k == notnull.size())
            if(i - l < mini) mini = i - l, l1 = l + 1, r1 = i + 1;
    }
    cout << l1 << ' ' << r1 << '\n';
}
