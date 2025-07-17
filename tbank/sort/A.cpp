
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

void bub_sort(vll &a) {
    ll n = a.size();
    bool f = true;
    while (f) {
        f = false;
        for (ll j = 0; j < n - 1; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                f = true;
            }
        }
        n--;
    }
}

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    bub_sort(a);
    for(ll c : a) cout << c << ' ';
    cout << '\n';
}
