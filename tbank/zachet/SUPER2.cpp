#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define ld long double
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

const ll inf = 1e9 + 7;

void rec(ll pos, ll k, vll & cur, vll & cubes, ll last) {
    if(k == 0) {
        ll s = 0;
        vll cur2;
        for(ll c : cur) if(c) cur2.push_back(c);
        cout << cur2.size() << '\n';
        for(ll c : cur2) {
            if(c) cout << cbrt(c) << ' ';
        }
        cout << '\n';
        exit(0);
    }
    for(ll i = last; i > -1 && pos != 8; i--) {
        if(cubes[i] > k) continue;
        last = i;
        // cout << cubes[i] << ' ';
        cur.push_back(cubes[i]);
        rec(pos + 1, k - cubes[i], cur, cubes, last);
        // cout << '\n';
        cur.pop_back();
    }
}

int main() {
    ll n;
    cin >> n;
    vll cubes;
    for(ll i = 0; i * i * i <= 2e9; i++)
        cubes.push_back(i * i * i);
    vll cur;
    rec(0, n, cur, cubes, cubes.size() - 1);
    cout << 0 << '\n';
}


