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

void solve() {
    string s, ss, cmd;
    ll ns, nss;
    cin >> ns >> s >> nss >> ss >> cmd;
    deque dq(all(s));
    for (ll i = 0; i < nss; i++) {
        if (cmd[i] == 'D') dq.push_back(ss[i]);
        if (cmd[i] == 'V') dq.push_front(ss[i]);
    }
    cout << string(all(dq)) << '\n';
}

int main() { ll t; cin >> t; while (t--) solve(); }