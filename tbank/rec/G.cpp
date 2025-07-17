// #pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc push_options
// #pragma gcc pop_options
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define f first
#define s second
#define all(a) a.begin(), a.end() 

using namespace std;

void rec(ll pos, ll n, ll k, vll & cur) {
    if(k == 0) {
        for(ll c : cur) cout << c << ' ';
        cout << '\n';
        return;
    }
    for(ll i = k; i >= cur[pos - 1]; i--) {
        cur.push_back(i);
        rec(pos + 1, n, k - i, cur);
        cur.pop_back();
    }
}

int main() {
    ll n;
    cin >> n;
    vll cur;
    for(ll i = n; i > 0; i--) {
        cur.push_back(i);
        rec(1, n, n - i, cur);
        cur.pop_back();
    }
}
