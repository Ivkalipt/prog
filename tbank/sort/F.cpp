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

const ll inf = 1e9 + 7;

int part(vll & a, ll l, ll h) {
    
    ll pivot = a[h];
    ll r = l - 1;

    for (ll j = l; j < h; j++) {
        if (a[j] < pivot) {
            r++, swap(a[r], a[j]);
        }
    }
    
    swap(a[r + 1], a[h]);  
    return r + 1;
}

void quickSort(vll & a, ll l, ll h) {
  
    if (l < h) {
      
        ll pivo = part(a, l, h);
        quickSort(a, l, pivo - 1);
        quickSort(a, pivo + 1, h);
    }
}

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    quickSort(a, 0, n - 1);
  
    for (ll & c : a) cout << c << ' ';
    cout << '\n';
    return 0;
}
