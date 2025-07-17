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

int main() {
    fastio;
    ll t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        ll x = b - a;
        if(x >= 0) a -= x;
        cout << max(a, 0LL) << '\n';
    }
}
