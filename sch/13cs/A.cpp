#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

void selection_sort(vll & a, ll k) {
   for (ll i = 0; i < (ll)a.size() - 1; i++) {
        ll mini = i;
        for(ll j = i + 1; j < a.size(); j++){
            if (a[j] < a[mini])
                mini = j;
        }
        if(a[i] % k == a[mini] % k)
            swap(a[i], a[mini]);
   }
}

bool issort(vll & a) {
    for(ll i = 1; i < a.size(); i++) {
        if(a[i] > a[i - 1]) return false;
    }
    return true;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for(ll & c : a) cin >> c;
    vll b = a;
    selection_sort(a, k);
    sort(all(b));
    for(ll i = 0; i < n; i++) {
        // cout << a[i] << ' ' << b[i] << '\n';
        if(a[i] != b[i]) cout << "NO\n", exit(0);
    }
    cout << "YES\n";
}
