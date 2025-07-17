#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e16;

int main() {
    ll q;
    cin >> q;
    while(q--) {
        ll l, r, s = 0;
        cin >> l >> r;
        ll cnt = r - l + 1;
        if(cnt < 9) {
            for(ll i = l; i <= r; i++) {
                s += (i % 9 ? i % 9 : 9);
            }
        }
        else {
            s += cnt / 9 * 45;
            ll p = (r % 9 ? r % 9 : 9);
            ll end = (l % 9 ? l % 9 : 9);
            while(end != (p + 1) % 9) {
                s += end;
                end++;
                if(end == 10) end = 1;
            }
        }
        cout << s << '\n';

    }
}
