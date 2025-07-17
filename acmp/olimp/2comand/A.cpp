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

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    set<ll> b(all(a));
    if(b.size() > 3) cout << "No\n";
    else {
        vll p(all(b));
        if(p.size() == 1) cout << "Yes\n1\n";
        if(p.size() == 2) cout << "Yes\n" << p[1] - p[0] << '\n';
        if(p.size() == 3) {
            if(p[2] - p[1] != p[1] - p[0]) cout << "No\n";
            else cout << "Yes\n" << p[2] - p[1] << '\n';
        }
    }
    
}

