#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll cnt = 0;
    ll chk = (k % 2 == 1 ? k - 1 : k);
    ll nchk = (k % 2 == 0 ? k - 1 : k);
    if(n & 1) n -= nchk, cnt++;
    cnt += ((n + chk - 1) / chk);
    cout << cnt << '\n';
    
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
