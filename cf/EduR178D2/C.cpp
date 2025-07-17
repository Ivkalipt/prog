#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll inf = 1e18;
ll n;

bool check(ll a, ll b) {
    if(a == 1 && b == n) return 1;
    if(b == 1 && a == n) return 0;
    if(a > b) return 1;
    return 0;
}

void solve() {
    string s;
    cin >> n >> s;
    for(ll i = 0; i < n; i++) {
        if(s[i] == 'A') {
            bool f = 1;
            for(ll j = 0; j < n; j++) {
                // cout << s[j] << ' ' << check(j + 1, i + 1) << '\n';
                if(s[j] == 'B' && check(j + 1, i + 1)) {
                    f = 0;
                }
            }
            if(f) {
                cout << "Alice\n";
                return;
            }
        }
    }
    cout << "Bob\n";
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
