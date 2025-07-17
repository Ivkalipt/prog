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

vll count_sort(vll & a)
{
    ll N = 1e4 + 1;
    map<ll, ll> cnt;
    vll sorted;
    for(ll c : a) {
        if(cnt.count(c)) cnt[c]++;
        else cnt[c] = 1;
    }
    for(auto v : cnt) {
        for(ll i = 0; i < v.S; i++) {
            sorted.push_back(v.F);
        }
    }
    return sorted;
}

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    vll sorted = count_sort(a);
    for(ll c : sorted) cout << c << ' ';
    cout << '\n';
}
