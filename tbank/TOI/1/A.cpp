#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e9 + 7;

int main() {
    ll n, m, t, l = 1, s = 0;
    cin >> n >> m;
    bool f = 1;
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    // vvll a(n + 1, vll(m + 1, 0));
    for(ll j = 1; j <= m; j++) {
        if(f) {
            for(ll i = 1; i <= n; i++) {
                // a[i][j] = l;
                if(min(r1, r2) <= i && i <= max(r2, r1) && min(c1, c2) <= j && j <= max(c2, c1)) s += l % inf;
                l++;
            }
            f = 0;
        }
        else {
            for(ll i = n; i > 0; i--) {
                // a[i][j] = l;
                if(min(r1, r2) <= i && i <= max(r2, r1) && min(c1, c2) <= j && j <= max(c2, c1)) s += l % inf;
                l++;
            }
            f = 1;

        }
    }

    /*for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }*/
    cout << s % inf << '\n';
}
