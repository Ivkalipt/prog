
#pragma gcc optimize ("o3,unroll-loops")
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

const ll inf = 1e9 + 7;

void ins_sort(vll &a)
{
    ll n = a.size();
    for (ll i = 0; i < n - 1; i++) {
            for (ll j = i + 1; j < n; j++) {
                if (a[i] > a[j]) swap(a[i], a[j]);
            }
        }
}

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    ins_sort(a);
    for(ll c : a) cout << c << ' ';
    cout << '\n';
}
