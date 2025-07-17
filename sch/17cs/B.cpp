#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<long long>;

const ll maxn = 10000;

bool a[maxn];

int main() {
    ll n, m;
    cin >> n >> m;
    for(ll i = 2; i <= m + 1; i++) {
        for(ll j = i; j <= n; j++) {
            if(j % i == 0) a[j] = !a[j];
        }
    }
    ll cnt = 0;
    for(ll i = 1; i <= n; i++)
        if(a[i]) cnt++;
    cout << cnt << '\n';
}
