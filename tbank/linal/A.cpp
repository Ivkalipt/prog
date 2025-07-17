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

ll inf = 1e16;

struct sw {
    deque<pll> d;
    ll l = 0, r = 0;
    
    void push_back(ll n) {
        while(!d.empty() && d.back().F >= n) d.pop_back();
        d.emplace_back(n, r);
        r++;
    }
    
    void pop_front() {
        if(d.front().second == l) d.pop_front();
        l++;
    }
    
    ll get_min() { 
        return d.empty() ? inf : d.front().F;
    }
};

int main() {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    sw window;
    for(ll & c : a) cin >> c;
    for(ll i = 0; i < k; i++) {
        window.push_back(a[i]);
    }
    for(ll i = k; i <= n; i++) {
        cout << window.get_min() << ' ';
        window.pop_front();
        window.push_back(a[i]);
    }
}
