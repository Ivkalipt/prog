#include <string>
// #pragma GCC optimize ("O3, unroll-all-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

ll inf = 1e9 + 7;

bool check(ll n) {
    string ns = to_string(n);
    for(char c : ns) if(c == '7') return true;
    return false;
}


void bfs(ll x) {
    unordered_map<ll, ll> d;
    d[x] = 0;
    if(check(x)) {
        cout << 0 << '\n';
        return;
    }
    queue<ll> q;
    q.push(x);
    while(!q.empty()) {
        ll v = q.front();
        q.pop();
        for(ll i = 9; i < 1e9; i = i * 10 + 9) {
            if(!d.count(v + i)) d[v + i] = inf;
            if(d[v + i] > d[v] + 1) {
                d[v + i] = d[v] + 1;
                q.push(v + i);
                if(check(v + i)) {
                    cout << d[v + i] << '\n';
                    return;
                }
            }
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        bfs(x);
    }
}
