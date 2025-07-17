#pragma GCC optimize ("Ofast")

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

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt1 = 0, cnt_ = 0;
    for(char c : s) {
        if(c == '-') cnt1++;
        else cnt_++;
    }
    cout << cnt_ * ((cnt1 / 2) * (cnt1 - cnt1 / 2)) << '\n';
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
