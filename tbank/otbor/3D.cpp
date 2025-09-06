#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr ll MAX_TIME = 1e3;
constexpr ll MAX_CORD = 5e5;

int main() {
    fastio;
    ll t, s;
    cin >> t >> s;
    
    if (s == t) {
        cout << 0 << '\n';
        return 0;
    }
    
    ll max_time = 0;
    if (s <= MAX_CORD) {
        max_time = min(1000LL, (ll)(sqrtl(2 * (MAX_CORD - s)) + 1));
    }
    
    vll kisa_pos;
    kisa_pos.reserve(max_time + 1);
    
    ll pos = s;
    for (ll tx = 0; tx <= max_time; tx++) {
        if (pos > MAX_CORD) break;
        kisa_pos.push_back(pos);
        pos += tx + 1;
    }

    
    unordered_set<ll> visited;
    queue<pair<ll, ll>> q; // {x, time}
    
    q.push({t, 0});
    visited.insert(t * (max_time + 1) + 0);
    
    ll ans = INF;
    
    while (!q.empty()) {
        ll x = q.front().F;
        ll time = q.front().S;
        q.pop();
        
        if (time < kisa_pos.size() && x == kisa_pos[time]) {
            ans = min(ans, time);
            continue;
        }
        
        if (time >= max_time || ans != INF) {
            continue;
        }
        
        ll moves[3] = {x - 1, x + 1, 2 * x};
        
        for (ll next : moves) {
            if (next >= 0 && next <= MAX_CORD) {
                ll state = next * (max_time + 1) + (time + 1);
                if (visited.find(state) == visited.end()) {
                    visited.insert(state);
                    q.push({next, time + 1});
                }
            }
        }
    }
    
    cout << (ans == INF ? -1 : ans) << '\n';
    
    return 0;
}
