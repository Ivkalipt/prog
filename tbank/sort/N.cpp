#pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define f first
#define s second
#define all(a) a.begin(), a.end() 
#define rall(a) a.rbegin(), a.rend()

using namespace std;

const ll inf = 1e9 + 7;

ll cnt = 0;

vll merge(vll a, vll b) {
    ll i = 0, j = 0;
    vll res;
    while(i < a.size() && j < b.size()) {
        if(a[i] > b[j]) res.push_back(b[j++]), cnt += a.size() - i;
        else res.push_back((a[i++]));
    }
    while(i < a.size()) res.push_back(a[i++]);
    while(j < b.size()) res.push_back(b[j++]);
    return res;
}

vll merge_sort(vll a) {
    if(a.size() < 2) return a;
    ll mid = a.size() / 2;
    return merge (
                merge_sort(vll(a.begin(), a.begin() + mid)), 
                merge_sort(vll(a.begin() + mid, a.end()))
            );

}

int main() {
    ll n, l;
    cin >> n >> l;
    vll a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = i + a[i] * l;
        // cout << a[i] << ' ';
    }
    vll sorted = merge_sort(a);
    cout << cnt << '\n';
}
