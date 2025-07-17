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

ll cnt = 0;

void bub_sort(vll &a) {
    ll n = a.size();
    bool f = true;
    while (f) {
        f = false;
        for (ll j = 0; j < n - 1; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                f = true;
                cnt++;
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
    cout << cnt << '\n';
}
