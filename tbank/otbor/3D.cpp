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
constexpr ll MAX_CORD = 5e5;

int main() {
    fastio;
    ll t, s;
    cin >> t >> s;
    ll max_time = 1, to_cord = t;
    while (to_cord <= MAX_CORD) {
        to_cord += max_time;
        max_time++;
    }

    set<ll> kotty_pos;
    vll used(MAX_CORD + 1, -1);
    kotty_pos.insert(t);

    for (ll i = 0; i <= max_time; i++) {
        ll curr_kissy_pos = s + (1 + i) * i / 2;

        if (curr_kissy_pos > MAX_CORD) break;

        if (kotty_pos.count(curr_kissy_pos)) {
            cout << i << '\n';
            return 0;
        }

        set<ll> new_kotty_pos;
        for (ll x : kotty_pos) {
            for (ll new_x : {x + 1, x - 1, 2 * x}) {
                if (new_x < 0 || new_x > MAX_CORD) continue;
                new_kotty_pos.insert(new_x);
            }
        }
        kotty_pos = set(all(new_kotty_pos));
    }
    cout << -1 << '\n';
}
