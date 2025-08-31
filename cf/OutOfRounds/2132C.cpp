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
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll MAXD = 20;

ll pow3[MAXD + 1], costs[MAXD], deal_by_x[MAXD];

void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for (ll i = 19; i >= 0; i--) {
        deal_by_x[i] = n / pow3[i];
        ans += deal_by_x[i] * costs[i];
        n %= pow3[i];
    }
    ll deal_sum = 0;
    for (ll x : deal_by_x) deal_sum += x;
    if (deal_sum > k) { cout << -1 << '\n'; return; }
    ll free_deal_2 = (k - deal_sum) / 2;
    for (ll i = 19; i > 0; i--) {
        if (deal_by_x[i] <= free_deal_2) {
            deal_by_x[i - 1] += 3 * deal_by_x[i];
            free_deal_2 -= deal_by_x[i];
            deal_by_x[i] = 0;
        }
        else {
            deal_by_x[i - 1] += 3 * free_deal_2;
            deal_by_x[i] -= free_deal_2;
            break;
        }
    }
    deal_sum = 0;
    for (ll i = 0; i < MAXD; i++) deal_sum += deal_by_x[i] * costs[i];
    cout << deal_sum << '\n';
}

int main() {
    pow3[0] = 1;
    for (ll i = 1; i < MAXD + 1; ++i)
        pow3[i] = pow3[i - 1] * 3;
    costs[0] = 3;
    for (ll i = 1; i < MAXD; ++i)
        costs[i] = pow3[i + 1] + i * pow3[i - 1];
    // for (ll x : costs) cout << x << ' ';
    ll t; cin >> t; while (t--) solve();
}