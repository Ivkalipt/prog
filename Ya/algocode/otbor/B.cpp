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

int main() {
    ll n;
    cin >> n;
    multiset<ll> after_talon;
    queue<ll> q;
    while (n--) {
        string type;
        cin >> type;
        if (type == "talon") {
            ll x;
            cin >> x;
            q.push(x);
        }
        if (type == "mashinka") {
            if (after_talon.empty()) {
                cout << q.front() << endl;
                q.pop();
            }
            else {
                cout << *after_talon.begin() << endl;
                after_talon.erase(after_talon.begin());
            }
        }
        if (type == "level") {
            while (!q.empty()) {
                after_talon.insert(q.front());
                q.pop();
            }
        }

    }

}