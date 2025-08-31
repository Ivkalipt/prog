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

int main() {
    ll n;
    cin >> n;
    vll a(n + 1), p(n + 1), pref(n + 1);
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 1; i <= n; i++) {
        cin >> p[i];
        pref[i] = pref[i - 1] + p[i];
    }
    vll Vl(n + 1), Vr(n + 2);
    for (ll i = 1; i <= n; i++)
        Vl[i] = Vl[i - 1] + (a[i] - a[i - 1]) * pref[i - 1];
    for (ll i = n; i > 0; i--)
        Vr[i] = Vr[i + 1] + (a[i + 1] - a[i]) * (pref[n] - pref[i]);
    /*for (ll i = 1; i <= n; i++)
        cout << Vl[i] << ' ';
    cout << '\n';
    for (ll i = 1; i <= n; i++)
        cout << Vr[i] << ' ';*/
    ll mn = INF, ind = -1;
    for (ll i = 1; i <= n; i++) {
        if (mn > Vl[i] + Vr[i]) {
            mn = Vl[i] + Vr[i];
            ind = i;
        }
    }
    cout << ind << '\n';
}