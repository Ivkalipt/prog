#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

const int MAXN = 2e5 + 1;

struct Point {
    ll x, y, id;
};

void solve() {
    ll n;
    cin >> n;
    vector<Point> a(n);
    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        a[i] = {x, y, i + 1};
    }
    sort(all(a),
        [&] (const Point ai, const Point bi) {return ai.x < bi.x;});
    ll k = n / 2;
    vector<Point> Lpart(a.begin(), a.begin() + k), Rpart(a.begin() + k, a.end());
    sort(Lpart.begin(), Lpart.end(),
             [&](const Point ai, const Point bi) {return ai.y < bi.y;});
    sort(Rpart.begin(), Rpart.end(),
         [&](const Point ai, const Point bi) {return ai.y > bi.y;});
    for (ll i = 0; i < k; i++) {
        cout << Lpart[i].id << ' ' << Rpart[i].id << '\n';
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) solve();
}