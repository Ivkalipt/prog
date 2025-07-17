// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
// #pragma GCC optimize ("Ofast")

#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;


int main()
{
    fastio;
    ll n1, n2;
    cin >> n1;
    vll a(n1);
    for(ll &c : a) cin >> c;
    cin >> n2;
    vll b(n2);
    for(ll &c : b) cin >> c;
    set<ll> a1(all(a));
    set<ll> b1(all(b));
    vll c;
    set_symmetric_difference(all(a1), all(b1), back_inserter(c));
    cout << c.size() << '\n';
    for(ll v : c) cout << v << ' ';
    cout << '\n';

}
