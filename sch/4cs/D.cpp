// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll int64_t
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
// #define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define N 31

using namespace std;

template <typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (auto &x : a) out << x << ' ';
    out << '\n';
    return out;
} 

template <typename T>
istream &operator>>(istream &in, vector<T> &a) {
    for (auto &x : a) in >> x;
    return in;
}

int main() {
    fastio;
    vll a(N);
    ll s, pay = 0;
    cin >> s >> a;
    
    for(ll i = 1; i < N; i++)
        if(a[i] < 2 * a[i - 1])
            a[i] = 2 * a[i - 1];

    for(ll i = N; i > -1; i--) {
        if(s >= a[i]) {
            s -= a[i];
            pay += (1LL << i);
        }
        // cout << s << ' ' << a[i] << '\n';
    }
    if(s > 0) pay++;
    cout << pay << '\n';

}
