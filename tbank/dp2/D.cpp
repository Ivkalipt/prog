#include <algorithm>
#pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

const ll inf = 1e16;

int main() {
    ll n, a1, k, b, m, l = 0;
    cin >> n >> a1 >> k >> b >> m;
    vll a(n);
    a[0] = a1;
    for(ll i = 1; i < n; i++) a[i] = (k * a[i - 1] + b) % m;
    vll dp(n + 1, inf), p(n, -1), pos(n + 1, 0);
    pos[0] = -1;
    dp[0] = -inf;
    for(ll i = 0; i < n; i++) {
        ll j = upper_bound(all(dp), a[i]) - dp.begin();
        if(dp[j - 1] < a[i] && a[i] < dp[j]) {
            dp[j] = a[i];
            pos[j] = i;
            p[i] = pos[j - 1];
            l = max(l, j);
        }
    }
    ll ind = pos[l];
    vll ans;
    while(ind != -1) {
        ans.push_back(a[ind]);
        ind = p[ind];
    }
    cout << l << '\n';
    reverse(all(ans));
    for(ll c : ans) cout << c << ' ';
    cout << '\n';

}

