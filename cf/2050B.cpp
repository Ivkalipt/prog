#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("Ofast")

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

ll inf = 1e16;

using namespace std;

int main() {
    ll _;
    cin >> _;
    while(_--) {
        ll n;
        cin >> n;
        ll even = 0, odd = 0;
        for(ll i = 1; i <= n; i++) {
            ll t; cin >> t;
            if(i & 1) odd += t;
            else even += t;
        }
        ll a = n / 2;
        ll b = n - a;
        if(even % a == 0 && odd % b == 0 && even / a == odd / b) cout << "Yes\n";
        else cout << "No\n";
    }
}
