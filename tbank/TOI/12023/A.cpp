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

ll inf = 1e18;

int main() {
    ll n, mini = inf, max_x, max_y;
    cin >> n;
    for(ll x = 1; x * x * x <= n; x++) {
        /*if(n % x == 0) {
            ll a = n / x;
            ll y = sqrtl((x * x * x) / n);
            if((ll)sqrt(a) * (ll)sqrt(a) == a) {
                if(x + y < mini) mini = x + y, max_x = x, max_y = y;
            }
            // cout << x << ' ' << y << '\n';
            ll x2 = n / x;
            a = n / x2;
            y = sqrtl((x2 * x2 * x2) / n);
            if((ll)sqrt(a) * (ll)sqrt(a) == a) {
                if(x2 + y < mini) mini = x2 + y, max_x = x2, max_y = y;
            }
            // cout << x2 << ' ' << y << '\n';

        }*/
        ll x3 = x * x * x;
        if(x3 % n == 0) {
            ll y2 = x3 / n;
            if((ll)sqrt(y2) * (ll)sqrt(y2) == y2) {
                ll y = sqrtl(y2);
                ll x = y2 * n;
                if(x + y < mini) mini = x + y, max_x = x, max_y = y;
            }
        }

    }
    cout << max_x << ' ' << max_y << '\n';
}
